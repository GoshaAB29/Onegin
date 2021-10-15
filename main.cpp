#include "include/onegin.h"
#include <iostream>

#define NOT_FROM_CMD

/* TODO:
1) Correct some issues mention in comments
2) Docs
*/

//! main function (for sorting text)

int main(int argc, char *argv[])
{
    setlocale (LC_ALL, "ru_Ru.cp1251");

    Text text = {};

    #ifdef NOT_FROM_CMD
        argv[1] = "test1.txt";
    #endif

    text_init (&text, argv[1]);

    do_sorting (&text, BASE_SORT);
    write_to_file (&text, "sorted.txt");

    do_sorting (&text, REVERSE_SORT);
    write_to_file (&text, "sorted_reverse.txt");

    free_text (&text);

    printf ("Sorting is done");

    return 0;
}
