#ifndef EDITS_KEYS
#define EDITS_KEYS

typedef enum {
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN
} EDT_EscSeq;

typedef enum {
    EDT_ESC_SEQ,
    CHAR8_KEY
} EDT_KeyResultTag;

typedef struct {
    EDT_KeyResultTag tag;
    union {
        EDT_EscSeq esc_seq;
        Char8 chr;
    };
} EDT_KeyResult;

void EDT_processKey(EDT_KeyResult result);
EDT_KeyResult EDT_readKey();


EDT_KeyResult EDT_makeEscSeqResult(EDT_EscSeq key);
EDT_KeyResult EDT_makeCharKeyResult(Char8 chr);

#endif // EDITS_KEYS
