#include "core/include/logger.h"
#include "core/include/debug/assert.h"
#include "core/include/string.h"
#include <stdio.h>

int main() {
    LOG_FATAL("test %s", "fatal");
    LOG_ERROR("test %s", "error");
    LOG_WARNING("test %s", "warning");
    LOG_INFO("test %s", "info");
    LOG_DEBUG("test %s", "debug");
    LOG_TRACE("test %s", "trace");

    //should not abord program
    ASSERT(1);
    //should abort program
    ASSERT_MSG(stringFormat(0), "Error during string formating");

    printf("Should not be displayed");
    return 0;
}

