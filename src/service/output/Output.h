/*
 * Отвечает за работу с дисплеем
 * Выводит данные и очищает консоль
 */

#ifndef LENTI_OUTPUT_SERVICE_H
#define LENTI_OUTPUT_SERVICE_H


#include "colors.h"
#include "shared/uefi.h"

class Output {
private:
    static void print(const wchar_t *msg, COLOR color);
public:
    static void clear();
    static void     log(const wchar_t *msg);
    static void    info(const wchar_t *msg);
    static void success(const wchar_t *msg);
    static void warning(const wchar_t *msg);
    static void   error(const wchar_t *msg);
};


#endif //LENTI_OUTPUT_SERVICE_H
