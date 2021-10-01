#include "../header/onegin.h"

void number_of_lines (Text *text)
{
    assert (text->buffer);

    for (int num_smb_for_new_str = 0; num_smb_for_new_str < text->file_size;
        ++num_smb_for_new_str) {

        if (text->buffer[num_smb_for_new_str] == '\n')
            text->num_strings++;
    }

    text->str = (String*)calloc(text->num_strings, sizeof (String));
}

void read_buffer (Text *text, FILE *file)
{
    assert (text);
    assert (file);

    text->buffer = (char*)calloc (text->file_size + 1, sizeof (char));

    fread (text->buffer, sizeof (char), text->file_size, file);

    text->buffer[text->file_size] = '\0';
}

int compare (const void *first_str, const void *second_str)
{
    assert (first_str != nullptr);
    assert (second_str != nullptr);

    const String first  = *(String*)first_str;
    const String second = *(String*)second_str;

    int current_first = 0;
    int current_second = 0;

    if ((first.length == 0) && (second.length == 0))
        return 0;
    else {
        if (first.length == 0)
            return -1;
        if (second.length == 0)
            return 1;
    }

    while ((first.data[current_first] != '\0') &&
           (second.data[current_second] != '\0')) {

        if ((isalnum (first.data[current_first])) == 0)
            current_first++;
        if ((isalnum (second.data[current_second])) == 0)
            current_second++;

            if ((first.data[current_first] == second.data[current_second]) &&
                (isalnum (second.data[current_first]) != 0) &&
                (isalnum (second.data[current_first]) != 0)) {

                current_first++;
                current_second++;

            } else {

            //printf("%d : %d\n", first.data[current_first], second.data[current_second]);
                return first.data[current_first] -
                    second.data[current_second];
            }
    }
 //   printf (strtok(
    return first.length - second.length;
}

int compare_reverse (const void *first_str, const void *second_str)
{
    assert (first_str != nullptr);
    assert (second_str != nullptr);

    const String first  = *(String*)first_str;
    const String second = *(String*)second_str;

    int current_first = first.length - 1;
    int current_second = second.length - 1;

    //printf ("%d ", current_first);
    //printf ("%d\n", current_second);
    //printf ("%c\n", first.data[first.length - 2]);

    while ((current_first >= 0) &&
           (current_second >= 0)) {

        if ((isalnum (first.data[current_first])) == 0)
            current_first--;
        if ((isalnum (second.data[current_second])) == 0)
            current_second--;

        if (first.data[current_first] == second.data[current_second]) {
            current_first--;
            current_second--;

        } else
                return (first.data[current_first] -
                        second.data[current_second]);
    }

    return current_first - current_second;
}


void read_from_file (Text *text, const char *name)
{
    assert (text);
    struct stat buff;

    stat ("test1.txt", &buff);
    text->file_size = buff.st_size;

    FILE *for_sorting = fopen (name,"r");

    assert (for_sorting); // strtok
    read_buffer (text, for_sorting);
    number_of_lines (text);

    fclose (for_sorting);

    //printf ("%s", text->str[index + 1].data);
    //bool new_str = false;
    char *current = strtok (text->buffer, "\n");

    int index = 0;

    text->str[index].data = current;

    //text->str[index].length = current - text->buffer;
    index++;

    while (text->num_strings - index > 0) {

        current = strtok (NULL, "\n");
        text->str[index].data = current;
        text->str[index - 1].length = current - text->str[index - 1].data;

       // printf ("%d\n", current - text-> buffer);
//        printf ("index = %d, current = %d, length[i-1] = %d, data[i-1]= %d, len[i] = %d\n", index,
  //              current, text->str[index -1].length, text->str[index-1].data, text->str[index].length);

        //text->str[index].data[text->str[index].length - 1] = '\0';
        index++;
    }

    //text->str[index].data[text->str[index].length - 1] = '\0';

    //printf ("%s\n", text->str[0].data);
}

void do_sorting (Text *text)
{
    assert (text);
    qsort (text->str, text->num_strings, sizeof (String), compare);
}

void write_to_file (Text *text)
{
    FILE *sorted = fopen ("sorted.txt", "w");

    assert (text);
    assert (isfinite (text->file_size));
    assert (sorted);

    int num_str = 0;

    for (int current_line = 0; current_line < text->num_strings; ++current_line) {
        fputs (text->str[num_str++].data, sorted);
        fputc ('\n', sorted);
    }

    fclose (sorted);
}

void free_text (Text *text)
{
     text->file_size = -1;
     text->num_strings = -1;

     free(text->buffer);
     free(text->str);

     text->buffer = nullptr;
     text->str = nullptr;
}
