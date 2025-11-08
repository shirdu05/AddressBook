#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include<ctype.h>


void listContacts(AddressBook *addressBook, int sortCriteria) //collecting as pointer bcoz of *
{
    // Sort contacts based on the chosen criteria:
    int n = addressBook->contactCount;//no of contacts
    Contact temp; //temporary varible for swaping
    //here its prints the contact list
    if(sortCriteria ==4)
    {
        printf("    Name        Phone                   Email\n");
        for(int i=0;i<n;i++)
        {
            printf("%d.%-30s%-30s%-30s\n",i+1,
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
        }
        return;
    } //bubbble sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            int cmp=0;
            if(sortCriteria==1)
            cmp=strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
            else if(sortCriteria==2)
            cmp=strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
            else if(sortCriteria==3)
            cmp=strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email);

            if(cmp>0){ //here swaping if out of order
                temp=addressBook->contacts[j];
                addressBook->contacts[j]=addressBook->contacts[j+1];
                addressBook->contacts[j+1]=temp;
            }
        }
    } //printing sorted contacts
    printf("                 Name                           Phone                     Email\n");
    for(int i=0;i<n;i++)
    {
        printf("%-30s%-30s%-30s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
     loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) 
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
void createContact(AddressBook *addressBook)  //collecting in pointer
{
	/* Define the logic to create a Contacts */
   if(addressBook->contactCount>=MAX_CONTACTS)//check for the contacts full
    {
        printf("Adress Book is full\n");
        return;//if full exit
    }
    char name[50];
    char phone[50];
    char email[50];
    
    printf("Enter Name:");
    scanf("%[^\n]",name);
    getchar();//it takes next line 

    int ret_name=validate_name(name,addressBook);//here it checks name is correct
    if(ret_name == 0)
    {
      printf("Invalid name\n");//if not correct return 0;
      return;
    }
   //if name is correct continue the program......
    printf("Enter Phone Number:");
    scanf("%[^\n]",phone);
    getchar(); //placed to handle the newline

  int ret_phone=validate_phone(phone,addressBook);//check for phone is valid
    if(ret_phone == 0)
    {
      printf("Invalid phone no\n");//if not valid
      return;
    }
    //now email
    printf("Enter Email:");
    scanf("%[^\n]",email);
    getchar();
    //check mail is correct or not 
    int ret_email=validate_email(email,addressBook);

    if(ret_email == 0)
    {
      printf("Invalid innput\n");//if not correct
    }

    //copyinng input to structutre
    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,email);

    addressBook->contactCount++;
    //after creating increase the contactcount

    printf("\n Contact Created:\n");

}
//search contact by name,phone,email
int searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
  //int n=addressBook->contactCount;
  int option;
  printf("Enter Searching Options\n\n");//enter wt data u want
  printf("1.Search By Name\n");
  printf("2.Search By Number\n");
  printf("3.Search By Email\n");
  printf("Choose an Option :");
  scanf("%d",&option);
  getchar();
  char name[50];
  char phone[50];
  char email[50];
  int flag; //now flag
  switch (option)
  {
    case 1:
      {

        printf("Enter the name to search :");
    
        scanf(" %[^\n]",name);

        //chcek name is present or not
        for ( int i = 0 ; i < addressBook->contactCount ; i++ )
        {
          if ( strcasecmp(addressBook->contacts[i].name,name) == 0 )
          {
            
            //this will work for everymatch
            printf("%-10s%-30s%-15s%-30s\n","ID","Name","Number","Email");
            
            printf("%-10d%-30s%-15s%-30s\n",i,addressBook->contacts[i].name,
              addressBook->contacts[i].phone,addressBook->contacts[i].email);
            flag = 1; //if its 1 means there is a match
          }
        }
        if(flag==0)//if flag is 0 no data found
        {
          printf("name is not found\n");
        }
        break;
      }

        case 2:
      {
        printf("Enter the number to search :");
        scanf(" %[^\n]",phone);
        flag=0;
        //chcek if there is a match
        for ( int i = 0 ; i < addressBook->contactCount ; i++ )
        {
          if ( strcasecmp(addressBook->contacts[i].phone,phone) == 0 )
          {   //if u got match prints
            
            printf("%-10s%-30s%-15s%-30s\n","ID","Name","Number","Email");
            
            printf("%-10d%-30s%-15s%-30s\n",i,addressBook->contacts[i].name,
            addressBook->contacts[i].phone,addressBook->contacts[i].email);
            flag = 1; //indication for match
          }
        }
        if(flag==0) ///not match
        {
          printf("number is not found\n");
        }
        break;
      }

        case 3:
      {  
        printf("Enter the email to search :");//for searching emaill
        scanf(" %[^\n]",email);
        flag=0;

        //check if there is a match
        for ( int i = 0 ; i < addressBook->contactCount ; i++ )
        {
          if ( strcasecmp(addressBook->contacts[i].email,email) == 0 )
          { //if u got print it
          
            printf("%-10s%-30s%-15s%-30s\n","ID","Name","Number","Email");
            
            printf("%-10d%-30s%-15s%-30s\n",i,addressBook->contacts[i].name,
            addressBook->contacts[i].phone,addressBook->contacts[i].email);
            flag = 1;//indicates match
          }
        }
        if(flag==0)//not a match
        {
          printf("Email is not found\n");
        }
        break;
      }
      default:
      {
        printf("Invalid selection\n");
        break;
      }
  }
  if(flag ==1)
  {
    return 1;//if contact is found
  }
  else
  {
    return 0;//if contact is not found
  }

}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */

    int found=searchContact(addressBook);//found or not
    if(found==0)//if not found return 0
    {
      return;
    }
    else
    {
      int index;
    printf("Enter the index you want to edit: \n");
    scanf("%d",&index);

    printf("Enter edit details\n");
    printf("1.Name:\n");
    printf("2.Phone:\n");
    printf("3.Email:\n");

    int choice;
    printf("Enter what u want to edit:\n");
    scanf("%d",&choice);
    getchar();
    switch(choice)
    {
      case 1:
      {
        char new_name[50];//enter new name
        printf("Enter new name: ");
        scanf("%[^\n]",new_name);
        getchar();
        //check name is correct or not
        int ret_name=validate_name(new_name,addressBook);
        if(ret_name==0)
        {
          printf("Invalid input\n");
          return;
        }
        //if user enter invalid index it is fault
        //it will new copy
        strcpy(addressBook->contacts[index].name,new_name);
        printf("name edited...\n");
        break;
      }
    case 2:
      { ///for new phone no
        char new_phone[50];
        printf("Enter new phone:");
        scanf("%[^\n]",new_phone);
        getchar();
        //checking nre no is correct or not
        int ret_phone=validate_phone(new_phone,addressBook);
        if(ret_phone==0)
        {
          printf("Invalid input\n");
          return;
        }
      //copying
        strcpy(addressBook->contacts[index].phone,new_phone);
        printf("number edited..\n");
        break;
      }

    case 3:
     {  //for new mail
        char new_email[50];
        printf("Enter new Email:");
        scanf("%[^\n]",new_email);
        getchar();
      //checking mail is correct or not
        int ret_email = validate_email(new_email,addressBook);
        if(ret_email==0)
        {
          printf("Invalid input\n");
          return;
        }
        //copying
        strcpy(addressBook->contacts[index].email,new_email);
        printf("email edited...\n");
        break;
      } 
    default:
    {
    printf("Invalid choice\n");
    }
  }
    //printing the coontact..
  printf("---Edited contact---\n");

  printf("%-10s %-30s %-15s %-30s\n","Index","name","phone","Email");
  printf("%-10d %-30s %-15s %-30s\n",index,addressBook->contacts[index].name,
    addressBook->contacts[index].phone,
    addressBook->contacts[index].email);
 }
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
     if (searchContact(addressBook))
  {
    int index;
    printf("Enter the index you want to delete :");
    scanf("%d",&index);

    for (int i = index ; i < addressBook->contactCount ; i++ )
    {
      addressBook->contacts[i] = addressBook->contacts[i+1];
    }
      addressBook->contactCount--;
      //saveContactsToFile(addressBook); //save after delete
      printf("contact deleted");
  }
  else
  {
    printf("Data Not Found\n");
  }
}

int validate_name(char *name,AddressBook *addressBook)
{
  int i=0;
  while(name[i])
  {
    if(!((name[i]>='a'&& name[i]<='z')||(name[i]>='A'&& name[i]<='Z')||(name[i]==' ')))
    { //if char and space are not available means it will return 0;
      return 0;
    }
    i++;
  }
      return 1;
}

int validate_phone(char *phone,AddressBook *addressBook)
{ 
    if(strlen(phone)!=10)//check if no is not exactly 10 char long
    {
      return 0;
    }
  
    for(int i=0;phone[i]!='\0';i++)//ch(eck if char is digit
    {
      if(!isdigit(phone[i]))
      {
        return 0;
      }
    } //check for uniqueness
  for(int i=0;i<addressBook->contactCount;i++)
  {
    if(strcmp(addressBook->contacts[i].phone,phone)==0)
    {
      return 0;//if phone number alredy exist
    }
  }
  return 1;//if it is valid and unique
}
 int validate_email(char *email,AddressBook *addressBook)
{
  int i=0;
  int dot_count=0;
  int at_count=0;
  int dot_after_at=0;
  while(email[i]) //this loop interates entire prgm
  {
    if(email[i]==' ')//check for spaces
    {
      return 0; //return 0 if space found
    }
    if(email[i]=='@')
    {
      at_count++;
    }
    if(email[i]=='.') //for counting the dot
    {
      dot_count++;
    }
    if(at_count>0 && email[i]=='.') 
    {
      dot_after_at=1;//it checks the dot after at;
    }
    
    if(!((email[i]>='a' && email[i]<='z')||
    (email[i]>='0'&& email[i]<='9')||
    (email[i]=='.'||email[i]=='@'||email[i]==' ')))
    {
      return 0;
    }
    i++;
  } //now need to check only one at,atleat one dot,one dot should be after at
  if(at_count!=1||dot_count<0||dot_after_at==0||email[0]=='@'||email[0]=='.')
  {
    return 0;
  }
  return 1; //if all condition pass it si valid email
}
