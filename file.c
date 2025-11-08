#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    FILE *fptr=fopen("contacts.csv","w");//open and sae data in csv file

    if(fptr == NULL)
    {
        printf("file opening failed\n");
        return;
    }

     fprintf(fptr,"%d\n",addressBook->contactCount);

    for(int i=0;i<addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n",addressBook->contacts[i].name,
                                    addressBook->contacts[i].phone,
                                    addressBook->contacts[i].email);//printing data to file
    }
    fclose(fptr);
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *fptr=fopen("contacts.csv","r");//to open a file

    if(fptr == NULL)//check till null address or zero
    {
        printf("File opening failed\n");//if failed means
    }
    fscanf(fptr,"%d\n",(&addressBook->contactCount));

    for(int i=0;i<addressBook->contactCount;i++)
    {
        fscanf(fptr, "%[^,], %[^,], %[^\n]\n",addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);//data required
    }
    fclose(fptr);//clear
}
