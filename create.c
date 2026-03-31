#include "inverter.h"

void create(hash_t arr[], FILE_NAME* head)
{
    char single_word[25];
    FILE_NAME* temp_file_node = head;

    while (temp_file_node != NULL)
    {
        /* checking if the file already added or not */
        if (is_file_present(arr, temp_file_node->file_name))
        {
            printf("File %s already present. Skipping...\n",
                   temp_file_node->file_name);
            temp_file_node = temp_file_node->link;
            continue;
        }

        /* opening that file */
        FILE* fptr = fopen(temp_file_node->file_name, "r");
        if (fptr == NULL)
        {
            temp_file_node = temp_file_node->link;
            continue;
        }

        /* reading word from the file */
        while (fscanf(fptr, "%s", single_word) != EOF)
        {
            int index;

            if (single_word[0] >= 'a' && single_word[0] <= 'z')
                index = single_word[0] - 'a';
            else if (single_word[0] >= 'A' && single_word[0] <= 'Z')
                index = single_word[0] - 'A';
            else
                index = 26;

            /* checking if main node exists or not */
            if (arr[index].link == NULL)
            {
                main_node_t* new_main = create_main_node(single_word);
                sub_node_t* new_sub = create_sub_node(temp_file_node->file_name);

                new_main->sub_link = new_sub;
                arr[index].link = new_main;
            }
            else
            {
                main_node_t* temp_main_node = arr[index].link;
                main_node_t* prev_main_node = NULL;

                while (temp_main_node != NULL)
                {
                    if (strcmp(temp_main_node->word, single_word) == 0)
                        break;

                    prev_main_node = temp_main_node;
                    temp_main_node = temp_main_node->link;
                }

                /* if word not present */
                if (temp_main_node == NULL)
                {
                    main_node_t* new_main = create_main_node(single_word);
                    sub_node_t* new_sub = create_sub_node(temp_file_node->file_name);

                    new_main->sub_link = new_sub;

                    if (prev_main_node == NULL)
                        arr[index].link = new_main;
                    else
                        prev_main_node->link = new_main;
                }
                else
                {
                    /* word present -> check sub list */
                    sub_node_t* temp_sub = temp_main_node->sub_link;
                    sub_node_t* prev_sub = NULL;

                    while (temp_sub != NULL)
                    {
                        if (strcmp(temp_sub->filename,
                                   temp_file_node->file_name) == 0)
                            break;

                        prev_sub = temp_sub;
                        temp_sub = temp_sub->link;
                    }

                    /* if file name not present */
                    if (temp_sub == NULL)
                    {
                        sub_node_t* new_sub =
                            create_sub_node(temp_file_node->file_name);

                        if (prev_sub == NULL)
                            temp_main_node->sub_link = new_sub;
                        else
                            prev_sub->link = new_sub;

                        temp_main_node->file_count++;
                    }
                    else
                    {
                        temp_sub->word_count++;   // update word count
                    }
                }
            }
        }

        fclose(fptr);
        temp_file_node = temp_file_node->link;
    }
}

main_node_t* create_main_node(char* single_word)
{
    main_node_t* new_main = malloc(sizeof(main_node_t));
    if (new_main == NULL)
        return NULL;

    new_main->file_count = 1;
    strcpy(new_main->word, single_word);
    new_main->sub_link = NULL;
    new_main->link = NULL;

    return new_main;
}

sub_node_t* create_sub_node(char *filename)
{
    sub_node_t* new_sub = malloc(sizeof(sub_node_t));
    if (new_sub == NULL)
        return NULL;

    new_sub->word_count = 1;
    strcpy(new_sub->filename, filename);
    new_sub->link = NULL;

    return new_sub;
}

int is_file_present(hash_t arr[], char *filename)
{
    for (int i = 0; i < 27; i++)
    {
        main_node_t *temp_main = arr[i].link;

        while (temp_main != NULL)
        {
            sub_node_t *temp_sub = temp_main->sub_link;

            while (temp_sub != NULL)
            {
                if (strcmp(temp_sub->filename, filename) == 0)
                    return 1;   // File found

                temp_sub = temp_sub->link;
            }

            temp_main = temp_main->link;
        }
    }

    return 0;   // File not found
}