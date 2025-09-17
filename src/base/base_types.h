#ifndef BASE_TYPES_H
#define BASE_TYPES_H
typedef uint8_t      u8;
typedef uint16_t    u16;
typedef uint32_t    u32;
typedef uint64_t    u64;
typedef int8_t       i8;
typedef int16_t     i16;
typedef int32_t     i32;
typedef int64_t     i64;
typedef float       f32;
typedef double      f64;

#define bool u8
#define FALSE 0
#define TRUE 1

// make functions "internal" to the compilation unit, make everyint internal besides public facing apis
// if someone would import the parts as a lib
#define internal        static   
// when declared in file scope
#define global          static 
// when declared in function scope (will persist it's value over function calls
#define local_persist   static 

#define Bytes(n)      (n)
#define Kilobytes(n)  (n << 10)
#define Megabytes(n)  (n << 20)

#endif // BASE_TYPES_H
