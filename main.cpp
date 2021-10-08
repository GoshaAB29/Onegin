#include "include/onegin.h"
#include <iostream>

//#define DEBUG

/* TODO:
1) Correct some issues mention in comments (ok)
2) Docs
3) Debug program (ok)
4) Write your own sort (ok)
*/
int main(int argc, char *argv[])
{
    setlocale (LC_ALL, "ru_Ru.cp1251");

    Text text = {};

    #ifdef DEBUG
        argv[1] = "test1.txt";
    #endif

    text_init (&text, argv[1]);

    my_sorting (&text, BASE_SORT);
    write_to_file (&text, "sorted.txt");

    my_sorting (&text, REVERSE_SORT);
    write_to_file (&text, "sorted_reverse.txt");

    free_text (&text);

    printf ("Sorting is done");

    return 0;
}
