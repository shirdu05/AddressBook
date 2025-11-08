#include <stdio.h>
#include "contact.h"
#include <stdlib.h>
#include "file.h"
int main() {
    int choice;
    AddressBook addressBook;  //struct name and struct variable
    initialize(&addressBook); // Initialize the address book (pass by refrence)

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
            {
                int sortChoice;

                printf("\nContacts Menu:\n");
                printf("1. Sort by Name\n");
                printf("2.Sort by Phone\n");
                printf("3.Sort by Email\n");
                printf("4.Normal Order\n");

                printf("Enter your sort Choice:");
                scanf("%d",&sortChoice);
                  
                listContacts(&addressBook, sortChoice);
            }
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                exit(0);
            case 7:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
       return 0;
}
