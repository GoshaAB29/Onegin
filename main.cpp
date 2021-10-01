#include "header/onegin.h"
#include <iostream>

int main(int argc, char *argv[])
{
    setlocale (LC_ALL, "ru_Ru.cp1251");

    Text text = {};

    read_from_file (&text, "test1.txt"); //...argv[1]);
    do_sorting (&text);
    write_to_file (&text);

    free_text (&text);

    printf ("Sorting is done");

    return 0;
}
