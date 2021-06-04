#ifndef DWARF_API_H
#define DWARF_API_H

#include "include/DwarfDef.h"
#include "include/DwarfObject.h"

typedef DString PID, ProcessID;

//              the parent      the path       the privilege
WordPTR Execute(const WordPTR, const DString, const Bool root);
WordPTR LoadDynlib(const DString, const Bool root);
//                  the library    the symbol name
WordPTR DynlibSymbol(const WordPTR, const DString);
Bool    Executable(const DString);

WordPTR GetDwarf(const PID);

dwHeader_ptr GetBinaryInformation(const PID); // PID
dwSection GetBinarySection(const dwHeader_ptr, const WordPTR);

// information about the executable privileges

typedef enum DwarfLevel
{
    DL_ROOT = 2, // not recommended !!!!!!
    DL_ADMIN = 1,
    DL_USER = 0,

} dwLevel;

// tells about the exectuion level that the kernel authorized the application to execute
dwLevel ExecutionLevel(const PID);
Bool    DebuggerInDwarf(const WordPTR);

#endif // DWARF_API_H