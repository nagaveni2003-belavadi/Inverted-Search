#include "inverter.h"

int update(hash_t arr[], FILE_NAME* head)
{
    char backup_file[30];

    printf("Enter backup file name : ");
    scanf("%s", backup_file);

    /* Check .txt extension */
    char *ext = strstr(backup_file, ".txt");
    if (ext == NULL || strcmp(ext, ".txt") != 0)
    {
        printf("ERROR : Invalid file extension\n\n");
        return 0;
    }

    FILE *fptr = fopen(backup_file, "r");
    if (fptr == NULL)
    {
        printf("ERROR : Backup file not found\n\n");
        return 0;
    }

    char line[200];

    while (fscanf(fptr, "%s", line) != EOF)
    {
        int len = strlen(line);

        /* Validate format */
        if (line[0] != '#' || line[len - 1] != '#')
        {
            printf("ERROR : Invalid backup file format\n\n");
            fclose(fptr);
            return 0;
        }

        /* Remove last '#' */
        line[len - 1] = '\0';

        /* Skip first '#' */
        char *token = strtok(&line[1], ";");

        /* Index */
        int index = atoi(token);

        /* File count */
        token = strtok(NULL, ";");
        int file_count = atoi(token);

        /* Word */
        token = strtok(NULL, ";");

        main_node_t *new_main = malloc(sizeof(main_node_t));
        new_main->file_count = file_count;
        strcpy(new_main->word, token);
        new_main->sub_link = NULL;
        new_main->link = NULL;

        /* Insert main node */
        new_main->link = arr[index].link;
        arr[index].link = new_main;

        sub_node_t *last_sub = NULL;

        /* Loop file_count times to create sub nodes */
        for (int i = 0; i < file_count; i++)
        {
            /* Word count */
            token = strtok(NULL, ";");
            int word_count = atoi(token);

            /* Filename */
            token = strtok(NULL, ";");

            sub_node_t *new_sub = malloc(sizeof(sub_node_t));
            new_sub->word_count = word_count;
            strcpy(new_sub->filename, token);
            new_sub->link = NULL;

            if (new_main->sub_link == NULL)
            {
                new_main->sub_link = new_sub;
                last_sub = new_sub;
            }
            else
            {
                last_sub->link = new_sub;
                last_sub = new_sub;
            }
        }
    }

    fclose(fptr);
    printf("Database updated from file successfully from backup\n\n");
    return 1;
}
