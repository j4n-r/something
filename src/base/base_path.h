#ifndef BASE_PATH
#define BASE_PATH

typedef Enum PathType {
    RELATIVE_PATH,
    ABSOLUTE_PATH
}

typedef struct {
    String8 path;
    PathType type;
} Path;



#endif // BASE_PATH
