#ifndef DWARF_OBJECT_H
#define DWARF_OBJECT_H

#include "DwarfDef.h"

typedef struct DwarfOptional
{
    HWord   e_prvileges; // need root or user?
    HWord   e_password;

} dwOpt;

/*
* Section structure to store data about the section
* Section structure can store 2 sections, but default let's just store 1 section
*/
typedef struct DwarfSection
{
    Word e_header_size;

    WordPTR e_entry; // 0 if not present
    WordPTR e_sections;
    WordPTR e_symbols; // pointer to the import table structure
    WordPTR e_reloc; // relocation table structure
    dwRelocBase e_reloc; // relocation table in case if the address wasn't aviable

    Word e_number_sections;
    Word e_number_symbols;

    HWord e_flags;

    int e_pad; // padding (must be a multiple of 2)

} dwSection;

/*
*   Simple structure to tell to the loader where to relocate when a relocation is needed
*/
typedef struct DwarfRelocationBase
{
    Word e_virtual_address;
    Word e_size_section; // size of the current section structure

} dwRelocBase;

typedef enum DwarfExtension
{
    DW_EXEC = 0,
    DW_DYN = 1,
    DW_UNKNOWN = 2,
    
} dwExtension;

/*
* General information about the executable
* NOTE: e_system will for now be skipped
*/
typedef struct DwarfExecutable
{
    HWord e_ident[4]; // DWF\0
    HWord e_arch;
    HWord e_system; // Desktop? Portable?
    HWord e_linker[2]; // table that contains information about the linker
    HWord e_version; // version of the executable 1 if not specified
    HWord e_badge; // the badge of the executable <dwf.filename.badge_id> 
    HWord e_uniqueId; // used by the symbol resolver; <dwf.type.filename.version.arch>
    HWord e_type; // .dlb or .do ?

    dwOpt e_opt; // optional dwarf header (if not specified just construct the default one)
    // dwRes e_res; // resource structure

    Word e_header_size; 

} dwHeader;

typedef dwHeader* dwHeader_ptr;
typedef dwSection* dwSection_ptr;
typedef dwRelocBase* dwRelocBase_ptr;

#endif // !DWARF_OBJECT_H