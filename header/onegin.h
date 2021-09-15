#pragma once

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "TxLib.h"

static const int MAX_STR = 25000;
static const int BUFF_LENGTH = 1000;

struct String {
    int length = 0;
    char *data = nullptr;
};

struct Text {
    int num_line = 0;
    char buffer[BUFF_LENGTH] = "";
};

int read_from_file (char *index[], const char* name);

void do_sorting (char *index[], const int num_line);

void write_to_file (char *index[], const int num_line);

