#ifndef GRIZZLY_CLI_H
#define GRIZZLY_CLI_H

static struct argp_option options[] = {
        {"ast-dump",  'd', "FILE",      0,  "Produce ast to standard output" },
        { 0 }
};

/* Program version */
const char *argp_program_version = "0.0.0";

/* Program bug address */
const char *argp_program_bug_address = "https://github.com/Fihtangolz/grizzly/issues";

static const char argp_program_desc[] = "Grizzly - C11 language compiler";

struct arguments_t {
    char *target_file;
} arguments;

static error_t parse_opt (int key, char* arg, struct argp_state* state) {
    switch (key) {
        case 'd':
            arguments.target_file = arg;
            break;
    }
    return 0;
}

static struct argp argp = {options, parse_opt, 0, argp_program_desc};

error_t cli_parse_arg(int argc, char *argv[], struct arguments_t* args) {
    return argp_parse(&argp, argc, argv, 0, 0, args);
}

#endif //GRIZZLY_CLI_H
