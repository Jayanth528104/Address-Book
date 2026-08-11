#include <stdio.h>   // Standard input/output functions
#include "file.h"   // Header file containing file handling declarations

void saveContactsToFile(AddressBook *addressBook) {   // Function to save contacts into a CSV file
  
    FILE *fp = fopen("contacts.csv", "w");   // Open file in write mode
    if(fp == NULL)   // Check if file opened successfully
    {
        printf("No File Found\n");   // Display error message
        return;   // Exit function
    }

    for(int k=0;k<addressBook->contactCount;k++)   // Traverse all contacts
    {
        fprintf(fp, "%s,%s,%s\n",addressBook->contacts[k].name,addressBook->contacts[k].phone,addressBook->contacts[k].email);   // Write contact details into file
    }
    
    fclose(fp);   // Close the file
  
}

void loadContactsFromFile(AddressBook *addressBook) {   // Function to load contacts from CSV file

    FILE *fp = fopen("contacts.csv", "r");   // Open file in read mode

    if (fp == NULL)   // Check if file exists
    {
        printf("File not found!\n");   // Display error message
        return;   // Exit function
    }

    addressBook->contactCount = 0;   // Initialize contact count

    while (fscanf(fp, " %[^,],%[^,],%[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3)   // Read one contact at a time
    {
        addressBook->contactCount++;   // Increase contact count after successful read
    }

    fclose(fp);   // Close the file
}