#include "../header/onegin.h"

int read_from_file (char *index[], const char *name)
{
    Text text;

    FILE *for_sorting = fopen (name,"r");
    assert (for_sorting);

    while (true) {
        if (fgets(text.buffer, sizeof(text.buffer), for_sorting) == NULL)
            break;

        index[text.num_line] = strdup(text.buffer);
        text.num_line++;
    }

    fclose (for_sorting);
    return text.num_line;
}

void do_sorting (char *index[], const int num_str)
{
    for (int x = 0; x < num_str; x++) {       //улучшить О(n^2)
        for (int y = 0; y < num_str; y++) {   //добавить проверку следующих символов (в отд. функцию)
            if (index[x][0] < index[y][0]) {
                char *tmp = index[y];
                index[y] = index[x];
                index[x] = tmp;

            }
        }
    }
}

void write_to_file (char* index[], int num_line)
{
    FILE *sorted = fopen ("sorted.txt", "w");

    assert (isfinite(num_line));
    assert (sorted);

    for (int current_line = 0; current_line < num_line; ++current_line)
    {
       fputs (index[current_line], sorted);
    }
}
