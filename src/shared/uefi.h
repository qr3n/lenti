#ifndef LENTI_LOADER_DATA
#define LENTI_LOADER_DATA


#include <efi.h>

struct UEFI {
    EFI_HANDLE ImageHandle;
    EFI_SYSTEM_TABLE *SystemTable;
};

extern UEFI uefi;


#endif //LENTI_LOADER_DATA