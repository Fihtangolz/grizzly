#ifndef GRIZZLY_LOGGER_H
#define GRIZZLY_LOGGER_H

#include <stdbool.h>

typedef enum {
    LOGGER_VERBOSITY_OFF = 0,
    LOGGER_VERBOSITY_ERROR = 1,
    LOGGER_VERBOSITY_WARN = 2,
    LOGGER_VERBOSITY_INFO = 3,
    LOGGER_VERBOSITY_DEBUG = 4,
    LOGGER_VERBOSITY_TRACE = 5,
} logger_verbosity_t;

void logger_setup(logger_verbosity_t verbosity);

void logger_trace(const char *format, ...);
void logger_debug(const char *format, ...);
void logger_info(const char *format, ...);
void logger_warn(const char *format, ...);
void logger_error(const char *format, ...);

#endif // GRIZZLY_LOGGER_H