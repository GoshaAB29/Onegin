#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <sys\stat.h>
#include <string.h>
#include <ctype.h>
#include "TxLib.h"

struct String {
    int length = 0;
    char *data = nullptr;
};

struct Text {
    size_t file_size = 0;
    int num_strings = 0;
    String *str = nullptr;
    char *buffer = nullptr;
};

int compare (const void *lhs, const void *rhs);

int compare_reverse (const void *lhs, const void *rhs);

void text_init (Text *text, const char *name);

void do_sorting (Text *text);

void write_to_file (Text *text);

void free_text (Text *text);

void read_buffer (Text *text, FILE *file);

void count_number_of_lines (Text *text);
