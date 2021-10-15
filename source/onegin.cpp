#include "../include/onegin.h"

//#define DEBUG_BUFFER
//#define DEBUG_INIT
//#define DEBUG_SORT
//#define DEBUG_MYSORT

void read_buffer (Text *text, FILE *file)
{
    assert (text);
    assert (file);

    text->buffer = (char*)calloc (text->file_size + 1, sizeof (char));

    fread (text->buffer, sizeof (char), text->file_size, file);

    text->buffer[text->file_size] = '\0';

    #ifdef DEBUG_BUFFER
        printf ("buffer contains: \"%d\"", text->file_size);
    #endif
}

void count_number_of_lines (Text *text)
{
    assert (text->buffer);

    for (unsigned int num_smb_for_new_str = 0; num_smb_for_new_str < text->file_size;
        ++num_smb_for_new_str) {

        if (text->buffer[num_smb_for_new_str] == '\n')
            text->num_strings++;
    }

    text->str = (String*)calloc(text->num_strings, sizeof (String));

    #ifdef DEBUG_BUFFER
        printf ("the number of strings in buffer is %d\n", text->num_strings);
    #endif
}

int compare (const void *lh_str, const void *rh_str)
{
    assert (lh_str != nullptr);
    assert (rh_str != nullptr);

    const String lhs  = *(String*)lh_str;
    const String rhs = *(String*)rh_str;

    int current_lhs = 0;
    int current_rhs = 0;

    if ((lhs.data == NULL) && (rhs.data == NULL))
        return 0;
    if (lhs.data == NULL)
            return -1;
    if (rhs.data == NULL)
            return 1;

    while ((lhs.data[current_lhs] != '\0') &&
           (rhs.data[current_rhs] != '\0')) {

            if (lhs.data[current_lhs] == rhs.data[current_rhs]) {
                current_lhs++;
                current_rhs++;

            } else {

                if ((isalnum (lhs.data[current_lhs]) != 0) &&
                (isalnum (rhs.data[current_rhs]) != 0)) {
                    return lhs.data[current_lhs] -
                        rhs.data[current_rhs];

                } else {

                    if (isalnum (lhs.data[current_lhs]) == 0)
                        current_lhs++;
                    if (isalnum (rhs.data[current_rhs]) == 0)
                        current_rhs++;
                }
            }
    }
    return lhs.length - rhs.length;
}

int compare_reverse (const void *lh_str, const void *rh_str)
{
    assert (lh_str != nullptr);
    assert (rh_str != nullptr);

    const String lhs  = *(String*)lh_str;
    const String rhs = *(String*)rh_str;

    int current_lhs = lhs.length - 1;
    int current_rhs = rhs.length - 1;

    #ifdef DEBUG_SORT
        printf ("%d ", current_first);
        printf ("%d\n", current_second);
    #endif

    while ((current_lhs >= 0) &&
           (current_rhs >= 0)) {

        if (lhs.data[current_lhs] == rhs.data[current_rhs]) {
            current_lhs--;
            current_rhs--;

        } else {
            if ((isalnum (lhs.data[current_lhs]) != 0) &&
                (isalnum (rhs.data[current_rhs]) != 0)) {

                return (lhs.data[current_lhs] - rhs.data[current_rhs]);
            }  else {

                    if (isalnum (lhs.data[current_lhs]) == 0)
                        current_lhs--;
                    if (isalnum (rhs.data[current_rhs]) == 0)
                        current_rhs--;
            }
        }
    }
    return current_lhs - current_rhs;
}

void my_sorting (Text *text,  int type_sort)
{

    for (int x = 0; x + 1 < text->num_strings; x++) {
        for (int y = x + 1; y < text->num_strings; y++)
            if ((type_sort == BASE_SORT ? compare (&text->str[x], &text->str[y]):
                 compare_reverse (&text->str[x], &text->str[y])) > 0) {

                str_swap (&text->str[x], &text->str[y]);

                 #ifdef DEBUG_MYSORT
                    printf ("str[x], str[y] is %d, %d\n", &text->str[x], &text->str[y]);
                 #endif
            }
    }

}

void str_swap (String *str1, String *str2)
{
    #ifdef DEBUG_MYSORT
    printf ("str1, str2 before swap is %d, %d\n", str1, str2);
    #endif

    String tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;

    #ifdef DEBUG_MYSORT
    printf ("str1, str2 after swap is %d, %d\n", str1, str2);
    #endif
}

void text_init (Text *text, const char *name)
{
    assert (text);

    FILE *for_sorting = fopen (name, "r");

    assert (for_sorting);

    struct stat buff;

    fstat (fileno(for_sorting), &buff);
    text->file_size = buff.st_size;

    #ifdef DEBUG_BUFFER
            printf ("the file size is %d\n", buff.st_size);
    #endif

    read_buffer (text, for_sorting);
    count_number_of_lines (text);

    fclose (for_sorting);

    int index_str = 0;
    int current_symb = 0;
    int current_length = 0;

    text->str[index_str].data = text->buffer;

    #ifdef DEBUG_INIT
    printf ("text->str[index_str] address is %d\n", text->str[index_str].data);
    #endif

    while (index_str < text->num_strings) {    //    gdb  (code blocks debugger)

        if (text->buffer[current_symb] == '\n') {

            text->buffer[current_symb] = '\0';
            text->str[index_str].length = current_length;
            current_length = 0;
            if (index_str + 1 < text->num_strings)
                text->str[index_str + 1].data = text->buffer + current_symb + 1;

            index_str++;

        } else
            current_length++;

        current_symb++;
        if (text->buffer[current_symb] == '\r')
            text->buffer[current_symb] = ' ';

        #ifdef DEBUG_INIT
            printf ("current (%d) address is %p\n", index_str, text->str[index_str]);
            printf ("%d is length of [%d]\n", text->str[index_str].length, index_str);
        #endif
    }

    #ifdef DEBUG_INIT
    printf ("str[%d].data is %d\n", index_str, current_symb);
    for (int k = 0; k < 5; k ++)
    printf ("length [%d] is %d\n", k, text->str[k].length);

    int num_output_strings = 0;

    for (num_output_strings = 0; num_output_strings < text->num_strings;
         num_output_strings++) {
    printf ("%p\n", text->str[num_output_strings].data);
    printf ("%s:::\n", text->str[num_output_strings].data);
    }
    #endif DEBUG
}

void do_sorting (Text *text, int type_sort)
{
    assert (text);
    qsort (text->str, text->num_strings, sizeof (String),
           type_sort == BASE_SORT ? compare : compare_reverse);
}

void write_to_file (Text *text, const char *name)
{
    assert (*name);
    FILE *sorted = fopen (name, "w");

    assert (text);
    assert (isfinite (text->file_size));
    assert (sorted);

    for (int current_line = 0; current_line < text->num_strings; ++current_line) {
        fputs (text->str[current_line].data, sorted);
        fputc ('\n', sorted);
    }

    fclose (sorted);
}

void free_text (Text *text)
{
     text->file_size = -1;
     text->num_strings = -1;

     free (text->buffer);
     free (text->str);

     text->buffer = nullptr;
     text->str = nullptr;
}
