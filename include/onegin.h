/// text processing

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys\stat.h>
#include <string.h>
#include <ctype.h>
#include "TxLib.h"

/// basic string parameters

struct String {
    int length = 0;
    char *data = nullptr;
};

/// basic text parameters

struct Text {
    size_t file_size = 0;
    int num_strings = 0;
    String *str = nullptr;
    char *buffer = nullptr;
};

/// text sorting types

enum types_of_sort {
    BASE_SORT = 0,                 ///< direct sort
    REVERSE_SORT = 1,              ///< reverse sort
};


//-------------------------------------------------------------------
//! Forward compare strings
//!
//! @param [in] lhs - pointer to left string
//! @param [in] rhs - pointer to right string
//!
//! @return number, > 0, if lhs is less than rhs
//! (from the first to the last symbol), == 0 if lhs and rhs are equivalent,
//! and < 0, i rhs is more than lhs
//!
//! @note compare
//!
//-------------------------------------------------------------------

int compare (const void *lhs, const void *rhs);

//-------------------------------------------------------------------
//! Backward compare strings
//!
//! @param [in] lhs - pointer to left string
//! @param [in] rhs - pointer to right string
//!
//! @return number, > 0, if lhs is less than rhs
//! (from the last to the first symbol), == 0 if lhs and rhs are equivalent,
//! and < 0, i rhs is more than lhs
//!
//! @note reverse compare
//!
//-------------------------------------------------------------------

int compare_reverse (const void *lhs, const void *rhs);

//-------------------------------------------------------------------
//! swapping strings
//!
//! @param [in] str1 - pointer to first string
//! @param [in] str2 - pointer to second string
//!
//-------------------------------------------------------------------

void str_swap (String *str1, String *str2);



//-------------------------------------------------------------------
//! bubble sort
//!
//! @param [in] text - pointer to sortable text
//! @param [in] type_sort - type of sorting
//!
//-------------------------------------------------------------------

void my_sorting (Text *text, const int type_sort);

//-------------------------------------------------------------------
//!  quick sort
//!
//! @param [in] text - pointer to sortable text
//! and its parameters
//! @param [in] type_sort - type of sorting
//!
//-------------------------------------------------------------------

void do_sorting (Text *text, const int type_sort);



//-------------------------------------------------------------------
//!  creation and initialization text
//!
//! @param [in] text - pointer to sortable text
//! @param [in] name - the name of the file
//! where the source text comes from
//!
//-------------------------------------------------------------------

void text_init (Text *text, const char *name);

//-------------------------------------------------------------------
//!  writing sorted text to file
//!
//! @param [in] text - pointer to sorted text
//! @param [in] name - the name of the file
//! where the text is written
//!
//-------------------------------------------------------------------

void write_to_file (Text *text, const char *name);

//-------------------------------------------------------------------
//!  freeing memory occupied by text
//!
//! @param [in] text - pointer to sorted text
//! and its parameters
//!
//-------------------------------------------------------------------

void free_text (Text *text);



//-------------------------------------------------------------------
//!  reading text to buffer from the file
//!
//! @param [in] text - pointer to sortable text and its parameters
//!
//-------------------------------------------------------------------

void read_buffer (Text *text, FILE *file);

//-------------------------------------------------------------------
//!  counter of the number of lines in the text
//!
//! @param [in] text - pointer to sortable text and its parameters
//!
//-------------------------------------------------------------------

void count_number_of_lines (Text *text);
