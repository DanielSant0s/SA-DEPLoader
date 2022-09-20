
typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned int u32;
typedef signed int s32;

#define REL_TYPE 1
#define PROGBITS 1
#define NOBITS 8
#define REL 9
#define GLOBAL 1
#define WEAK 2
#define NOTYPE 0
#define OBJECT 1
#define FUNC 2
#define SECTION 3
#define R_MIPS_32 2
#define R_MIPS_26 4
#define R_MIPS_HI16 5
#define R_MIPS_LO16 6

typedef struct
{
	u8 ident[16];  // struct definition for ELF object header
	u16 type;
	u16 machine;
	u32 version;
	u32 entry;
	u32 phoff;
	u32 shoff;
	u32 flags;
	u16 ehsize;
	u16 phentsize;
	u16 phnum;
	u16 shentsize;
	u16 shnum;
	u16 shstrndx;
} elf_header_t;

typedef struct
{
    u32 sh_name;
    u32 sh_type;
    u32 sh_flags;
    u32 sh_addr;
    u32 sh_offset;
    u32 sh_size;
    u32 sh_link;
    u32 sh_info;
    u32 sh_addralign;
    u32 sh_entsize;
} section_header_t;

typedef struct 
{
    u32 st_name, st_value, st_size;
    u8 st_info, st_other;
    u16 st_shndx;
}elf_symbol_t;

typedef struct 
{
    u32 r_offset, r_info;
} elf_reloc_t;
