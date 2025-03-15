#pragma once

#define LOG_FATAL_ENABLED 1
#define LOG_ERROR_ENABLED 1
#define LOG_WARNING_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

typedef enum LOG_LEVEL {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARNING = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} LOG_LEVEL;

void log_output(LOG_LEVEL level, const char *message, ...);

#if LOG_FATAL_ENABLED == 1
#   define LOG_FATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);
#else 
#   define LOG_FATAL(message, ...)
#endif

#if LOG_ERROR_ENABLED == 1
#   define LOG_ERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#else 
#   define LOG_ERROR(message, ...)
#endif

#if LOG_WARNING_ENABLED == 1
#   define LOG_WARNING(message, ...) log_output(LOG_LEVEL_WARNING, message, ##__VA_ARGS__);
#else 
#   define LOG_WARNING(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
#   define LOG_INFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else 
#   define LOG_INFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
#   define LOG_DEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else 
#   define LOG_DEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
#   define LOG_TRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else 
#   define LOG_TRACE(message, ...)
#endif