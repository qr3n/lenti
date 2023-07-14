/*
 * Отвечает за взаимодействие с файловой системой.
 * Читает текстовые и исполняемые файлы
 */

#ifndef LENTI_FILESYSTEM_H
#define LENTI_FILESYSTEM_H


#include <efi.h>
#include "shared/uefi.h"

class Filesystem {
private:
    static EFI_FILE* openFile(const wchar_t *filename);
public:
    static const wchar_t *readTextFile(const wchar_t *filename);
};


#endif //LENTI_FILESYSTEM_H
