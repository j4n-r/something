#ifndef BASE_KEYS_H
#define BASE_KEYS_H

typedef enum {
    CTRL = 2000,
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
    ModKey mod;
    SpecialKey s_key;
    u8 bytes[4];  // valid UTF-8 bytes
    u8 size; 
} KeyEvent;

DEFINE_RESULT(KeyEvent)

#endif // BASE_KEYS_H
