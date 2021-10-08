#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
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

enum types_of_sort {
    BASE_SORT = 0,
    REVERSE_SORT = 1,
};


int compare (const void *lhs, const void *rhs);

int compare_reverse (const void *lhs, const void *rhs);

void str_swap (String *str1, String *str2);


void my_sorting (Text *text, const int type_sort);

void do_sorting (Text *text, const int type_sort);


void text_init (Text *text, const char *name);

void write_to_file (Text *text, const char *name);

void free_text (Text *text);


void read_buffer (Text *text, FILE *file);

void count_number_of_lines (Text *text);
