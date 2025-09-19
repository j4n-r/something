#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <wayland-client.h>
#include <string.h>
#include <stdlib.h>
#include "../wayland-resources/xdg-shell.h"
#include "../wayland-resources/xdg-shell.c"
#include "../wayland-resources/wlr-layer-shell.h"
#include "../wayland-resources/wlr-layer-shell.c"


struct client_state {
    // Globals
    struct wl_compositor *compositor;
    struct wl_registry *registry;
    struct wl_shm *shm;
    struct wl_display *wl_display;
    struct zwlr_layer_shell_v1 *zwlr_layer_shell;
    // Objects
    struct wl_surface *wl_surface;
    struct zwlr_layer_surface_v1 *zwlr_surface;
    // config
    uint32_t width; 
    uint32_t height;
};

static void
wl_buffer_release(void *data, struct wl_buffer *wl_buffer)
{
    /* Sent by the compositor when it's no longer using this buffer */
    wl_buffer_destroy(wl_buffer);
}

static const struct wl_buffer_listener wl_buffer_listener = {
    .release = wl_buffer_release,
};

static uint32_t
calc_argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
    uint8_t R = (r * a) / 255;
    uint8_t G = (g * a) / 255;
    uint8_t B = (b * a) / 255;
    return ((uint32_t)a << 24) | ((uint32_t)R << 16) | ((uint32_t)G << 8) | B;
}

static struct wl_buffer*
draw_frame(struct client_state *state)
{
    uint32_t bytes_per_pixel = 4; 
    uint32_t stride = state->width * bytes_per_pixel; // row size

    uint32_t size = state->width * state->height * bytes_per_pixel;
    int fd = memfd_create("wl_shm", 0);
    if (ftruncate(fd, size) != 0)
        exit(1);
    uint32_t *data = mmap(0, size, PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0);
    if (data == MAP_FAILED) {
            close(fd);
            return NULL;
    }

    struct wl_shm_pool *pool = wl_shm_create_pool(state->shm, fd, size);
    struct wl_buffer *buffer = wl_shm_pool_create_buffer(pool,
        0, state->width, state->height, stride, WL_SHM_FORMAT_ARGB8888);
    wl_shm_pool_destroy(pool);
    close(fd);

    for (uint32_t y = 0; y < state->height; y++) {
        for (uint32_t x = 0; x < state->width; x++) {
            data[y * state->width + x] = calc_argb(100, 255, 255,255); 
        }
    }
    munmap(data, size);
    wl_buffer_add_listener(buffer, &wl_buffer_listener, NULL);
    return buffer;
}

// ZWLR 
static void
zwlr_surface_configure(void *data,
                       struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1,
                       uint32_t serial, uint32_t width, uint32_t height)
{
    struct client_state *state = data;
    zwlr_layer_surface_v1_ack_configure(zwlr_layer_surface_v1, serial);
    struct wl_buffer *buffer = draw_frame(state);
    wl_surface_attach(state->wl_surface, buffer, 0, 0);
    wl_surface_commit(state->wl_surface);
}

static const struct
zwlr_layer_surface_v1_listener zwlr_surface_listener = {
    .configure = zwlr_surface_configure,
};


// WL
static void
registry_handle_global(void *data, struct wl_registry *wl_registry,
                                   uint32_t name, const char *interface,
                                   uint32_t version)
{
    struct client_state *state = data;
    if (strcmp(interface, wl_compositor_interface.name) == 0) {
        state->compositor = wl_registry_bind(wl_registry, name,
                                             &wl_compositor_interface, version);
    }
    if (strcmp(interface, wl_shm_interface.name) == 0) {
        state->shm = wl_registry_bind(
            wl_registry, name, &wl_shm_interface, version);
    }

    if (strcmp(interface, zwlr_layer_shell_v1_interface.name) == 0) {
        state->zwlr_layer_shell = wl_registry_bind(wl_registry, name,
                                                   &zwlr_layer_shell_v1_interface,
                                                   version);

        /* zwlr_layer_surface_v1_add_listener(state->zwlr_layer_shell, */
        /*                                    &zwlr_surface_listener, data); */
    }
    printf("interface: '%s', version: %d, name: %d\n", interface, version, name);
}

static void
registry_handle_global_remove(void *data,
                              struct wl_registry *wl_registry,
                              uint32_t name)
{
    ///
}

static const struct
wl_registry_listener registry_listener = {
    .global         = registry_handle_global,
    .global_remove   = registry_handle_global_remove
};


// Main
int main()
{
    struct client_state state = {0};
    state.width = 300;
    state.height = 200;
    state.wl_display = wl_display_connect(NULL);
    state.registry = wl_display_get_registry(state.wl_display);
    wl_registry_add_listener(state.registry, &registry_listener, &state);
	wl_display_roundtrip(state.wl_display);

    state.wl_surface = wl_compositor_create_surface(state.compositor);
    state.zwlr_surface = zwlr_layer_shell_v1_get_layer_surface(state.zwlr_layer_shell,
                                                               state.wl_surface,
                                                               0, 3 /* overlay */,
                                                               "launch"); 

    zwlr_layer_surface_v1_add_listener(state.zwlr_surface,
                                        &zwlr_surface_listener, &state);

    zwlr_layer_surface_v1_set_size(state.zwlr_surface, state.width, state.height);

    wl_surface_commit(state.wl_surface);

    while (wl_display_dispatch(state.wl_display)) {
        /* This space deliberately left blank */
    }
    wl_display_disconnect(state.wl_display);
    return 0;
}

