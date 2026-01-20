/*
    This C file does not define a main function and is related to no-main-asm-001.s
    To compile and link this file, use `make psylinux`.

    Note that the order of the files during linking is important, the .c file comes after the .s file,
    so that the symbol psylinux is defined before being referenced.
*/

// RV32: XLEN = 32 bits
// ABI: lpi32 (int/long/pointer = 32 bits)
int psylinux() {
    // char    c0 = 255; // 1 byte
    // short   c1 = 12345; // 2 bytes
    // int     c2 = 1234567890;
    // long    c3 = 1234567890; // 4 bytes in lp32
    // long long c4 = 1234567890123456789; // 8 bytes
    // float   c5 = 12345.5; // 4 bytes
    // double  c6 = 1234567890.12345; // 8 bytes
    // long double c7 = 1234567890.123456789; // 16 bytes
    // const char * const c8 = "Hello, PsyLinux!"; // pointer, 4 bytes in lp32
    // const char **c9 = &c8; // pointer, 4 bytes in lp32
    // *c9 = "Modified string.";
    volatile int b = 42; // volatile int
    
    return 0;
}
