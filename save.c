#include "inverter.h"

void save(hash_t arr[])
{
    char save_file[25];
    int i;

    for (i = 0; i < 27; i++)
    {
        if (arr[i].link != NULL)
            break;
    }

    if (i == 27)
    {
        printf("ERROR : Database is empty\n\n");
        return;
    }

    /* reading file name from user */
    printf("Enter the file name where you want to save : ");
    scanf(" %[^\n]", save_file);

    /* checking file extension */
    char* substr1 = strstr(save_file, ".txt");

    if (substr1 != NULL && strcmp(substr1, ".txt") == 0)
    {
        FILE* fptr = fopen(save_file, "w");
        if (fptr == NULL)
        {
            printf("ERROR : Unable to open file\n\n");
            return;
        }

        /* traversing hash table */
        for (int index = 0; index < 27; index++)
        {
            main_node_t* temp_main = arr[index].link;

            /* traversing main node */
            while (temp_main != NULL)
            {
                /* printing main node details into file */
                fprintf(fptr, "#%d;%d;%s;", index, temp_main->file_count, temp_main->word);

                /* traversing sub node */
                sub_node_t* temp_sub = temp_main->sub_link;
                while (temp_sub != NULL)
                {
                    fprintf(fptr, "%d;%s;", temp_sub->word_count, temp_sub->filename);
                    temp_sub = temp_sub->link;
                }

                /* close the line */
                fprintf(fptr, "#\n");

                temp_main = temp_main->link;
            }
        }

        fclose(fptr);
        printf("Database saved successfully into %s\n\n", save_file);
    }
    else
    {
        printf("ERROR : %s invalid file name extension\n\n", save_file);
        printf("Example : (filename.txt)\n");
    }
}