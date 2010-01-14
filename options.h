#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <stdio.h>
#include "parse.h"

typedef struct input_file {
    FILE* stream;
    char* filename;
    struct input_file* next;
} input_file;

typedef struct conf {
    void (*gen)(FILE*,node*);
    struct input_file* input_files;
    FILE* output_file;
    enum verbose_type {
        VERBOSE_FATAL = 0, /* 0 is the default verbosity */
        VERBOSE_ERROR,
        VERBOSE_WARNING,
        VERBOSE_INFO,
        VERBOSE_DEBUG
    } verbose;
} conf;

void print_usage();
int parse_cl_opts(int argc, char* argv[], conf* opts);

#endif // OPTIONS_H_
