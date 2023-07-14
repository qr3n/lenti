#include "Output.h"

void Output::print(const wchar_t *msg, COLOR color) {
    uefi.SystemTable->ConOut->SetAttribute(uefi.SystemTable->ConOut, color);
    uefi.SystemTable->ConOut->OutputString(uefi.SystemTable->ConOut, (CHAR16*)msg);
    uefi.SystemTable->ConOut->OutputString(uefi.SystemTable->ConOut, (CHAR16*)L"\n\r");
}

void Output::clear() {
    uefi.SystemTable->ConOut->ClearScreen(uefi.SystemTable->ConOut);
}

void Output::log(const wchar_t *msg) { print(msg, LOG_COLOR); }

void Output::info(const wchar_t *msg) { print(msg, INFO_COLOR); }

void Output::success(const wchar_t *msg) { print(msg, SUCCESS_COLOR); }

void Output::warning(const wchar_t *msg) { print(msg, WARNING_COLOR);}

void Output::error(const wchar_t *msg) { print(msg, ERROR_COLOR); }