#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[100];//u cana slo write in upper fun also
    int contactCount;//counting the contacts the we hv to print :value is garbagge: value
} AddressBook;

void createContact(AddressBook *addressBook);/*here we store the contacts */
int searchContact(AddressBook *addressBook); /*particulaar cont serach also compare with strcmp,strncmp*/
void editContact(AddressBook *addressBook); /*here modifying/edit the name or any other details*/
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
int validate_name(char *name,AddressBook *addressBook);//for correct name
int validate_phone(char *phone,AddressBook *addressBook);//for correct phone
int validate_email(char *email,AddressBook *addressBook);// for correct email
//void saveContactsToFile(AddressBook *AddressBook); at last we are writting this

#endif
