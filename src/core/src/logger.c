#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "../include/logger.h"
#include "../include/string.h"
#include "../include/debug/assert.h"

void write_log(LOG_LEVEL level, const char *message){
    FILE* consoleHandle = level > 1 ? stdout : stderr; 
    const char* colour_strings[6] = {"0;41", "1;31", "1;33", "1;32", "1;34", "1;30"};
    fprintf(consoleHandle,  "\033[%sm%s\033[0m\n",colour_strings[level], message);
}

void log_output(LOG_LEVEL level, const char *message, ...) {
    const char *levelStrings[6] = {"[FAT]", "[ERR]", "[WAR]", "[INF]", "[DEB]", "[TRA]"};

    __builtin_va_list argPtr;
    va_start(argPtr, message);
    char *formatedArgs = stringFormatVa(message, argPtr);

    char *formatedMessage = stringFormat("%s: %s", levelStrings[level], formatedArgs);
    free(formatedArgs);

    write_log(level ,formatedMessage);
    free(formatedMessage);
}

void report_assertion_failure(const char *expression, const char *message, const char *file, unsigned int line){
    if(!message){
        log_output(LOG_LEVEL_FATAL, "Assertion (%s) failed at (file:line): %s:%d", expression, file, line);
    }else {
        log_output(LOG_LEVEL_FATAL, "Assertion (%s) failed at (file:line): %s:%d\nmessage: %s", expression, file, line, message);
    }
    
}