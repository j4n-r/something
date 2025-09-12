#ifndef BASE_RESULT
#define BASE_RESULT

#define GENERIC_ERROR   0x01
#define OS_ERROR        0x02

typedef struct {
    u32 code;
    String8 msg;
} Error;

#define OK(T, data) (Result_##T){ .is_error = FALSE, .data = (data) }
#define ERR(T, err) (Result_##T){ .is_error = TRUE, .error = (err) }

#define DEFINE_RESULT(T)  \
    typedef struct {            \
        bool is_error;            \
        union {                 \
            T data;             \
            Error error;          \
        };                      \
    } Result_##T;


DEFINE_RESULT(u8) 
DEFINE_RESULT(String8)





#endif // BASE_RESULT
