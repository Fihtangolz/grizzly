#include <stdarg.h>
#include <stdio.h>

#include "logger.h"
#include "terminal/colours.h"
#include "terminal/styles.h"

//************************************************************

logger_verbosity_t logger_verbosity;

void logger_setup(logger_verbosity_t verbosity) {
    logger_verbosity = verbosity;
}

//************************************************************

typedef enum {
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5,
} log_level_t;

#define PRINT_LEVEL(format, colour)                                     \
    fprintf(stderr, format, colour, styles_bold, colours_reset,          \
            styles_reset);

static void print_log_level(log_level_t level) {
    switch (level) {
    case LOGGER_VERBOSITY_ERROR:
        PRINT_LEVEL("%s%serror%s%s", colours_red)
        break;
    case LOGGER_VERBOSITY_WARN:
        PRINT_LEVEL("%s%swarn%s%s", colours_yellow)
        break;
    case LOGGER_VERBOSITY_INFO:
        PRINT_LEVEL("%s%sinfo%s%s", colours_green)
        break;
    case LOGGER_VERBOSITY_DEBUG:
        PRINT_LEVEL("%s%sdebug%s%s", colours_magenta)
        break;
    case LOGGER_VERBOSITY_TRACE:
        PRINT_LEVEL("%s%strace%s%s", colours_cyan)
        break;
    }
}
//************************************************************

static void log_helper(log_level_t level, const char *format, va_list args) {
    if (logger_verbosity != LOGGER_VERBOSITY_OFF && logger_verbosity >= level) {
        print_log_level(level);
        fprintf(stderr, ": ");
        vfprintf(stderr, format, args);
        fprintf(stderr, "\n");
    }
}

//************************************************************

#define LOG(level)                                                      \
    {                                                                          \
        va_list args;                                                          \
        va_start(args, format);                                                \
        log_helper(level, format, args);                                       \
        va_end(args);                                                          \
    }

void logger_trace(const char *format, ...) {
    LOG(LOG_LEVEL_TRACE)
}

void logger_debug(const char *format, ...) {
    LOG(LOG_LEVEL_DEBUG)
}

void logger_info(const char *format, ...) { LOG(LOG_LEVEL_INFO) }

void logger_warn(const char *format, ...) { LOG(LOG_LEVEL_WARN) }

void logger_error(const char *format, ...) {
    LOG(LOG_LEVEL_ERROR)
}