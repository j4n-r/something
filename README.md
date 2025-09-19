# Something

### Conventions:
- Structs: PRE_ (prefix + CamelCase)
- base Functions: camelCase
- Functions with Prefix: PRE_camelCase 
- Functions without prefix: PascaleCase 
- Variables: snake_case 
- Macros: PRE_CAPS_LOCK

## TODO 
- [ ] Test String8 
  - Done for initilization and join stuff
- [ ] Implement Queue
- [ ] Test Queue

### Helper Commands

``` fish
 nix run .#test_ansi '\x1b[6n'
```

``` fish
 showkey -a
```

``` fish
 wayland-scanner client-header < wlr-layer-shell-unstable-v1.xml > wlr-layer-shell.h
```

## Resources
- https://wayland-book.com/
- https://www.rfleury.com/ 
- https://github.com/EpicGamesExt/raddebugger (ideas, and some interfaces are stolen from him)
- https://viewsourcecode.org/snaptoken/kilo

## Notes
- [ ] Bracketed paste mode:
- [ ] Resizes & signals:

### Keyboard input
Since the goal is to have vim like layers (normal, insert, visual) and most
of the shotcuts will be with a  <leader> key (SPC) i will not implement the kitty 
keyboard protocol since i do not all the modifier keys and this will make it compatible with all terminals 

