#include "inverter.h"

void search(hash_t arr[])
{
    /* reading word from user */
    char word_search[25];
    printf("Enter the word : ");
    scanf(" %s", word_search);

    int index;

    if (word_search[0] >= 'a' && word_search[0] <= 'z')
    {
        index = word_search[0] - 'a';
    }
    else if (word_search[0] >= 'A' && word_search[0] <= 'Z')
    {
        index = word_search[0] - 'A';
    }
    else
    {
        index = 26;
    }

    if (arr[index].link != NULL)
    {
        main_node_t* temp_main = arr[index].link;

        while (temp_main != NULL)
        {
            if (strcmp(temp_main->word, word_search) == 0)
            {
                printf("----------------------------------------------------------------------------\n");
                printf("Word %s present in %d files\n", temp_main->word, temp_main->file_count);

                sub_node_t* temp_sub = temp_main->sub_link;
                while (temp_sub != NULL)
                {
                    printf("In %s, the word present %d times\n",
                           temp_sub->filename, temp_sub->word_count);
                    temp_sub = temp_sub->link;   // updating sub node
                }

                printf("----------------------------------------------------------------------------\n");
                return;
            }

            temp_main = temp_main->link;   // updating main node
        }

        printf("ERROR : Word is not found\n\n");
        return;
    }
    else
    {
        printf("ERROR : Word is not found\n\n");
        return;
    }
}