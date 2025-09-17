#ifndef BASE_PATH_H
#define BASE_PATH_H

typedef Enum PathType {
    RELATIVE_PATH,
    ABSOLUTE_PATH
}

typedef struct {
    String8 path;
    PathType type;
} Path;



#endif // BASE_PATH_H
