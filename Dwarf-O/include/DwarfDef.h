#ifndef DWARF_DEF_H
#define DWARF_DEF_H

#include <stdint.h>

#if defined(__x86_64__)
#define DWARF_x86_64
typedef uint64_t* DWordPTR;
typedef uint64_t DWord;
#endif // __x86_64__

typedef uint32_t* WordPTR;
typedef uint16_t* HWordPTR;
typedef uint32_t Word;
typedef uint16_t HWord;

typedef char*    DString;
typedef short    Byte;
typedef Byte     Bool, Boolean;

#endif // !DWARF_DEF_H