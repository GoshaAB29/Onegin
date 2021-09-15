#include "header/onegin.h"

int main()
{
    setlocale (LC_ALL, "ru_Ru.cp1251");
    char *index[MAX_STR] = {0};

    //*index = (char *) realloc (*index, sizeof(char)*10);

    int num_str = read_from_file (index, "test1.txt");

    do_sorting (index, num_str);

    write_to_file (index, num_str);

    printf ("program completed");
    return 0;
}
