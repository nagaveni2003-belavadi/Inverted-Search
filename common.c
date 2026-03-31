#include "inverter.h"

/* validating the file name which are passed in CLA */
int validate_arguments(char argv[], FILE_NAME** head)
{
    /* checking .txt file extension */
    char* substr1 = strstr(argv, ".txt");

    if (substr1 != NULL)
    {
        if (strcmp(substr1, ".txt") != 0)
        {
            printf("ERROR : %s invalid file name extension\n", argv);
            return 0;
        }
        else
        {
            /* checking if file exists or not */
            FILE* fptr = fopen(argv, "r");
            if (fptr == NULL)
            {
                printf("ERROR : %s file is not present\n", argv);
                return 0;
            }
            else
            {
                /* checking content is present or not */
                fseek(fptr, 0, SEEK_END);
                long size = ftell(fptr);
                fclose(fptr);

                if (size == 0)
                {
                    printf("ERROR : %s file content is not present\n", argv);
                    return 0;
                }
                else
                {
                    /* checking if file name is duplicate or not */
                    if (*head == NULL)
                        return 1;

                    FILE_NAME* temp = *head;

                    while (temp != NULL)
                    {
                        if (strcmp(argv, temp->file_name) == 0)
                        {
                            printf("ERROR : %s file is already copied\n", argv);
                            return 0;
                        }
                        temp = temp->link;
                    }
                    return 1;
                }
            }
        }
    }
    else
    {
        printf("ERROR : %s invalid file name extension\n", argv);
        return 0;
    }
}

/* Insert at last for adding file name into linked list */
int insert_at_last(char argv[], FILE_NAME** head)
{
    FILE_NAME* new_node = malloc(sizeof(FILE_NAME));
    if (new_node == NULL)
        return 0;

    strcpy(new_node->file_name, argv);
    new_node->link = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return 1;
    }
    else
    {
        FILE_NAME* temp = *head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new_node;
        return 1;
    }
}

/* printing valid files for database */
int print_filename(FILE_NAME* head)
{
    if (head == NULL)
    {
        printf("ERROR : In node file is not present\n");
        return 0;
    }

    while (head)
    {
        printf(" %s -> ", head->file_name);
        head = head->link;
    }

    printf(" NULL\n");
    return 1;
}

/* to free the memories */
void destroy_hash(hash_t arr[])
{
    for (int i = 0; i < 27; i++)
    {
        main_node_t *temp_main = arr[i].link;

        while (temp_main != NULL)
        {
            sub_node_t *temp_sub = temp_main->sub_link;

            /* Free sub nodes */
            while (temp_sub != NULL)
            {
                sub_node_t *sub_next = temp_sub->link;
                free(temp_sub);
                temp_sub = sub_next;
            }

            main_node_t *main_next = temp_main->link;
            free(temp_main);
            temp_main = main_next;
        }

        arr[i].link = NULL;
    }
}