#include "string.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char* stringFormatVa(const char *format, void *vaList){
    if(!format){
        return 0;
    }

    va_list listCopy;
    va_copy(listCopy, vaList);

    int length = vsnprintf(0, 0, format, listCopy);
    va_end(listCopy);

    char *buffer = malloc(length + 1);

    if(!buffer){
        return 0;
    }

    vsnprintf(buffer, length +1, format, vaList);
    buffer[length] = 0;

    return buffer;
}

char* stringFormat(const char* format, ...) {
    if(!format){
        return 0;
    }

    __builtin_va_list argPtr;
    va_start(argPtr, format);

    char *vaFormatedString = stringFormatVa(format, argPtr);
    va_end(argPtr);

    return vaFormatedString;
}