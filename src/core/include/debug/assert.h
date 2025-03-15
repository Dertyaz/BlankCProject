#pragma once

#include <stdlib.h>

#define ASSERTION_ENABLED 1

void report_assertion_failure(const char *expression, const char *message, const char *file, unsigned int line);
#if ASSERTION_ENABLED == 1
    #define ASSERT(expr)                                            \
    {                                                               \
        if(expr){                                                   \
        }else{                                                      \
            report_assertion_failure(#expr, 0, __FILE__, __LINE__); \
            abort();                                                \
        }                                                           \
    }

    #define ASSERT_MSG(expr, message, ...) \
    {                                                                       \
        if(expr){                                                           \
        }else{                                                              \
            report_assertion_failure(#expr, message, __FILE__, __LINE__);   \
            abort();                                                        \
        }                                                                   \
    }
#else
    #define ASSERT(expr)
    #define ASSERT_MSG(expr, message, ...)
#endif
