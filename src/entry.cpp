#include <efi.h>
#include "shared/uefi.h"
#include "core/Core.h"

[[noreturn]] EFIAPI EFI_STATUS entry(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    uefi.ImageHandle = ImageHandle;
    uefi.SystemTable = SystemTable;

    Core::main();

    while(true);
}