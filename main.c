/* Name = Nagaveni Belavadi
 * Date = 25/02/2026
 * Project = Inverted search

Description :
* Developed an Inverted Search Project that creates an inverted index to map keywords with their respective document IDs for fast and efficient information retrieval.

* Implemented text preprocessing techniques such as tokenization, case normalization, and stop-word removal to enhance search accuracy.

* Utilized C programming and Data Structures (Linked List, Hash Table, File Handling) to efficiently store, update, and retrieve indexed data.

* Improved search performance by avoiding full document scans and enabling quick keyword-based lookup with optimized time complexity.

 Supported multi-file indexing and keyword-based searching, making the project scalable for handling large text datasets. 

*/
#include "inverter.h"

int main(int argc, char* argv[])
{
    if(argc == 1)
    {
        printf("ERROR : Invalid command line arguments\n");
        return 0;
    }
    FILE_NAME* head = NULL;
    /*arguments validation*/
    for(int i=1;i<argc;i++)
    {
        if(validate_arguments(argv[i],&head)==1)
        {
            insert_at_last(argv[i],&head);
        }
    }
    print_filename(head);
    hash_t arr[27];
    for(int i=0;i<27;i++)
    {
        arr[i].index = i;
        arr[i].link = NULL;
    }
    create(arr,head);
    while(1)
    {
        int opt;
        printf("\t\t::::::Menu::::::\n");
        printf("1.Create database \n2.Display database \n3.Save database \n4.Search database \n5.Update database\n6.Exit\n");
        printf("Enter the option : " );
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                create(arr,head);
                break;

            case 2:
                display(arr);
                break;
            
            case 3:
                save(arr);
                break;
            
            case 4:
                search(arr);
                break;
            
            case 5:
                //update();
                break;

            case 6:
                return 0;
                break;

            default:
                break;
        }
        printf("Do you want to continue ? (1.yes)(2.No) :");
        scanf("%d",&opt);
        if(opt == 2)
            break;
    }
    return 0;
}