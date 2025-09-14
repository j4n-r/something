#ifndef BASE_KEYS
#define BASE_KEYS

typedef enum {
    CTRL == 2000,
    ALT,
    SUPER,
} ModKey ;

typedef enum {
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN,
  ESC
} SpecialKey;

typedef struct {
    Modkey mod;
    SpecialKey s_key;
    u8 bytes[4];  // valid UTF-8 bytes
    u8 size; 
} KeyEvent;

DEFINE_RESULT(KeyEvent);

#ifndef // BASE_KEYS
