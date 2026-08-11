#ifndef CONTACT_H   // Checks whether CONTACT_H is already defined
#define CONTACT_H   // Defines CONTACT_H to prevent multiple inclusion

#define MAX_CONTACTS 100   // Maximum number of contacts allowed

typedef struct {   // Structure to store a single contact
    char name[50];   // Stores contact name
    char phone[20];   // Stores contact phone number
    char email[50];   // Stores contact email address
} Contact;

typedef struct {   // Structure to store the address book
    Contact contacts[MAX_CONTACTS];   // Array of contact structures
    int contactCount;   // Stores the current number of contacts
} AddressBook;


int validateName(char []);   // Function prototype to validate name
int validatePhone(AddressBook *addressBook,char []);   // Function prototype to validate phone number
int validateEmail(AddressBook *addressBook,char []);   // Function prototype to validate email

void createContact(AddressBook *addressBook);   // Function prototype to create a contact
void searchContact(AddressBook *addressBook);   // Function prototype to search a contact
void editContact(AddressBook *addressBook);   // Function prototype to edit a contact
void deleteContact(AddressBook *addressBook);   // Function prototype to delete a contact
void listContacts(AddressBook *addressBook);   // Function prototype to list all contacts
void initialize(AddressBook *addressBook);   // Function prototype to initialize the address book
void saveContactsToFile(AddressBook *addressBook);   // Function prototype to save contacts into a file

#endif   // Ends the header guard