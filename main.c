/*
Description :
Name            : M K Jayanth Kumar
Roll No         : 26012B_085
Start date      : 17/07/2026
End date        : 22/07/2026
Sample input    : 

1. Create Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. List All Contacts
6. Exit
Enter your choice  : 1

Sample output   : 
Enter your choice  : 1

Enter Name         : Luffy

Enter Phone Number : 9191919191

Enter Email        : onepeice1@gmail.com

Contact Created Successfully
*/
#include <stdio.h>   // Standard input/output header
#include "contact.h"   // Header file containing address book declarations

int main() {   // Main function
    char choice;   // Variable to store user's menu choice
    AddressBook addressBook;   // Declare address book structure
    initialize(&addressBook); // Initialize the address book

    do {   // Repeat until user chooses Exit
        printf("\nAddress Book Menu:\n");   // Display menu title
        printf("1. Create contact\n");   // Create contact option
        printf("2. Search contact\n");   // Search contact option
        printf("3. Edit contact\n");   // Edit contact option
        printf("4. Delete contact\n");   // Delete contact option
        printf("5. List all contacts\n");   // List contacts option
        printf("6. Exit\n");   // Exit option
        printf("Enter your choice: ");   // Prompt for user's choice
        scanf(" %c", &choice);   // Read menu choice
        
        switch (choice) {   // Perform operation based on user's choice
            case '1':
                createContact(&addressBook);   // Create a new contact
                break;

            case '2':
                searchContact(&addressBook);   // Search for a contact
                break;

            case '3':
                editContact(&addressBook);   // Edit an existing contact
                break;

            case '4':
                deleteContact(&addressBook);   // Delete a contact
                break;

            case '5':
                listContacts(&addressBook);   // Display all contacts
                break;

            case '6':
                printf("Saving and Exiting...\n");   // Display exit message
                saveContactsToFile(&addressBook);   // Save contacts to file
                break;

            default:
                printf("Invalid choice. Please try again.\n");   // Handle invalid menu choice
        }

    } while (choice != '6');   // Continue until user selects Exit
    
    return 0;   // Indicate successful program termination
}