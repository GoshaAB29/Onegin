#include "include/onegin.h"
#include <iostream>

#define DEBUG

/* TODO:
1) Correct some issues mention in comments (ok)
2) Docs
3) Debug program (ok)
4) Write your own sort
*/
int main(int argc, char *argv[])
{
    setlocale (LC_ALL, "ru_Ru.cp1251");

    Text text = {};

    #ifdef DEBUG
        argv[1] = "test1.txt";
    #endif

    text_init (&text, argv[1]);
    do_sorting (&text);
    write_to_file (&text);

    free_text (&text);

    printf ("Sorting is done");

    return 0;
}
