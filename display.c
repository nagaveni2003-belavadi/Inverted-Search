#include "inverter.h"

void display(hash_t arr[])
{
    int index;

    /* loop to check if database exists */
    for (index = 0; index < 27; index++)
    {
        if (arr[index].link != NULL)
            break;
    }

    /* if all index link parts are NULL */
    if (index == 27)
    {
        printf("No database exist\n\n");
        return;
    }

    printf("\t\t::::::Created database::::::\n");
    printf("+-------+---------+----------------+---------+----------------------+\n");
    printf("| Index | FileCnt | Word           | WordCnt | Filename             |\n");
    printf("+-------+---------+----------------+---------+----------------------+\n");

    for (index = 0; index < 27; index++)
    {
        /* traversing hash index */
        if (arr[index].link != NULL)
        {
            /* traversing main node */
            main_node_t* temp_main_node = arr[index].link;

            while (temp_main_node != NULL)
            {
                /* traversing sub node */
                sub_node_t* temp_sub_node = temp_main_node->sub_link;

                while (temp_sub_node != NULL)
                {
                    /* printing the details */
                    printf("| %-5d | %-7d | %-14s | %-7d | %-20s |\n",
                           index,
                           temp_main_node->file_count,
                           temp_main_node->word,
                           temp_sub_node->word_count,
                           temp_sub_node->filename);

                    temp_sub_node = temp_sub_node->link;
                }

                temp_main_node = temp_main_node->link;
            }
        }
    }

    printf("+-------+---------+----------------+---------+----------------------+\n\n");
}
