#ifndef TYPES_H
#define TYPES_H

// Minimal fixed-width types for bare-metal RV32 without libc headers.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef unsigned int usize;

typedef u32 bool32;
#define TRUE32 1u
#define FALSE32 0u

#endif
