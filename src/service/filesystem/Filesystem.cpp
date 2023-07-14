#include <efi.h>
#include <efilib.h>
#include "Filesystem.h"

EFI_FILE *Filesystem::openFile(const wchar_t *filename) {
    EFI_FILE *File;
    EFI_FILE *Directory;

    EFI_LOADED_IMAGE_PROTOCOL *LoadedImage;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *FileSystem;

    /*
     * Загрузить дескриптор изображения.
     * Используется для получения информации о загруженном файле
     */
    uefi.SystemTable->BootServices->HandleProtocol(
            uefi.ImageHandle,
            &gEfiLoadedImageProtocolGuid,
            (void**)&LoadedImage);

    /*
     * Загрузить протокол доступа к файловой системе.
     * Позволяет открывать директории и файлы
     */
    uefi.SystemTable->BootServices->HandleProtocol(
            LoadedImage->DeviceHandle,
            &gEfiSimpleFileSystemProtocolGuid,
            (void**)&FileSystem);

    FileSystem->OpenVolume(FileSystem, &Directory);

    EFI_STATUS status = Directory->Open(
            Directory,
            &File,
            (CHAR16*)filename,
            EFI_FILE_MODE_READ,
            EFI_FILE_READ_ONLY);

    // Если не удалось открыть файл, то возвращаем null
    if (status != EFI_SUCCESS) return nullptr;

    return File;
}

const wchar_t *Filesystem::readTextFile(const wchar_t *filename) {
    auto File = openFile(filename);

    if (File == nullptr)
        return nullptr;

    UINT64 size;
    UINT8* buffer;

    File->GetInfo(File, &gEfiFileInfoGuid, &size, nullptr);

    uefi.SystemTable->BootServices->AllocatePool(EfiLoaderData, size, (void**)&buffer);

    File->Read(File, &size, buffer);

    File->Close(File);

    return reinterpret_cast<wchar_t*>(buffer);
}