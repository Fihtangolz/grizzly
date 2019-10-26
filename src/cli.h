#ifndef GRIZZLY_CLI_H
#define GRIZZLY_CLI_H

static struct argp_option options[] = {
        {"verbose",  'v', 0,      0,  "Produce verbose output" },
        {"quiet",    'q', 0,      0,  "Don't produce any output" },
        {"silent",   's', 0,      OPTION_ALIAS },
        {"output",   'o', "FILE", 0,
                                      "Output to FILE instead of standard output" },
        { 0 }
};

static struct argp argp = {options};

struct arguments
{
    char *args[2];                /* arg1 & arg2 */
    int silent, verbose;
    char *output_file;
};


#endif //GRIZZLY_CLI_H
