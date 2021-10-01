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
    char *buffer = nullptr;
    String *str = nullptr;
};

int compare (const void *first_str, const void *second_str);

int compare_reverse (const void *first_str, const void *second_str);

void read_from_file (Text *text, const char *name);

void do_sorting (Text *text);

void write_to_file (Text *text);

void free_text (Text *text);

void read_buffer (Text *text, FILE *file);

void number_of_lines (Text *text);
