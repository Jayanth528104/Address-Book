#ifndef FILE_H   // Checks whether FILE_H is already defined
#define FILE_H   // Defines FILE_H to prevent multiple inclusion

#include "contact.h"   // Includes the contact header file

void saveContactsToFile(AddressBook *addressBook);   // Function prototype to save contacts to a file
void loadContactsFromFile(AddressBook *addressBook);   // Function prototype to load contacts from a file

#endif   // Ends the header guard