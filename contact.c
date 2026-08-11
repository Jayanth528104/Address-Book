#include <stdio.h>   // Standard input/output header
#include <stdlib.h>  // Standard library functions
#include <string.h>  // String handling functions
#include "contact.h" // Contact structure and declarations
#include "file.h"    // File handling function declarations

void listContacts(AddressBook *addressBook) // Function to list contacts based on sorting criteria
{
    // Sort contacts based on the chosen criteria
    int sortCriteria = 0; // Variable to store user's sorting choice
    do
    {
        printf("Select sort criteria:\n"); // Display menu
        printf("1. Sort by name\n");
        printf("2. Sort by phone\n"); 
        printf("3. Sort by email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &sortCriteria); // Read user's choice
        switch (sortCriteria)       // Check selected option
        {
        case 1:
            printf("Sorting based on Name\n"); // Sort contacts by name

            for (int i = 0; i < addressBook->contactCount - 1; i++) // Outer loop for Bubble Sort
            {
                for (int j = 0; j < addressBook->contactCount - i - 1; j++) // Inner loop for Bubble Sort
                {
                    if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0) // Compare names
                    {
                        Contact temp = addressBook->contacts[j];                 // Store current contact temporarily
                        addressBook->contacts[j] = addressBook->contacts[j + 1]; // Swap contacts
                        addressBook->contacts[j + 1] = temp;                     // Complete swap
                    }
                }
            }
            printf("-------------------------------------------------------------------------------\n"); // Table header
            printf("Index\tName\t\t\tPhone\t\tEmail\n");
            printf("-------------------------------------------------------------------------------\n");
            for (int i = 0; i < addressBook->contactCount; i++) // Display all contacts
            {
                printf("%-5d %-25s %-15s %-35s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
            printf("-------------------------------------------------------------------------------\n"); // Table footer

            sortCriteria = 0; // Exit loop
            break;
        case 2:
            printf("Sorting based on Phone\n");                     // Sort contacts by phone
            for (int i = 0; i < addressBook->contactCount - 1; i++) // Outer loop
            {
                for (int j = 0; j < addressBook->contactCount - i - 1; j++) // Inner loop
                {
                    if (strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0) // Compare phone numbers
                    {
                        Contact temp = addressBook->contacts[j];                 // Temporary variable for swapping
                        addressBook->contacts[j] = addressBook->contacts[j + 1]; // Swap contacts
                        addressBook->contacts[j + 1] = temp;                     // Complete swap
                    }
                }
            }
            printf("-------------------------------------------------------------------------------\n"); // Table header
            printf("Index\tName\t\t\ttPhone\t\tEmail\n");
            printf("-------------------------------------------------------------------------------\n");
            for (int i = 0; i < addressBook->contactCount; i++) // Display sorted contacts
            {
                printf("%-5d %-25s %-15s %-35s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
            printf("-------------------------------------------------------------------------------\n"); // Table footer

            sortCriteria = 0; // Exit loop
            break;
        case 3:
            printf("Sorting based on Email\n");                     // Sort contacts by email
            for (int i = 0; i < addressBook->contactCount - 1; i++) // Outer loop
            {
                for (int j = 0; j < addressBook->contactCount - i - 1; j++) // Inner loop
                {
                    if (strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0) // Compare emails
                    {
                        Contact temp = addressBook->contacts[j];                 // Temporary variable
                        addressBook->contacts[j] = addressBook->contacts[j + 1]; // Swap contacts
                        addressBook->contacts[j + 1] = temp;                     // Complete swap
                    }
                }
            }
            printf("-------------------------------------------------------------------------------\n"); // Table header
            printf("Index\tName\t\t\tPhone\t\tEmail\n");
            printf("-------------------------------------------------------------------------------\n");
            for (int i = 0; i < addressBook->contactCount; i++) // Display sorted contacts
            {
                printf("%-5d %-25s %-15s %-35s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            }
            printf("-------------------------------------------------------------------------------\n"); // Table footer
            sortCriteria = 0;                                                                            // Exit loop
            break;
        case 4:
            printf("Exiting\n"); // Exit message
            sortCriteria = 0;    // Exit loop
            break;
        default:
            printf("Enter valid choice\n"); // Invalid choice message
            sortCriteria = 1;               // Continue loop
        }
    } while (sortCriteria); // Repeat until user exits
}

void initialize(AddressBook *addressBook) // Function to initialize address book
{
    addressBook->contactCount = 0; // Initialize contact count

    // populateAddressBook(addressBook);
    loadContactsFromFile(addressBook); // Load contacts from file

    // Load contacts from file during initialization (After files)
    // loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) // Function to save contacts and exit
{
    saveContactsToFile(addressBook);   // Save contacts into file
    printf("Saving and Exiting...\n"); // Display saving message
    exit(EXIT_SUCCESS);                // Terminate the program successfully
}
int validateName(char temp_name[]) // Function to validate the entered name
{
    int len = strlen(temp_name); // Calculate length of the name
    if (len < 3)                 // Check minimum length
    {

        printf("Error Message: Name must contain more than 3 characters\n"); // Display error
        return 0;                                                            // Invalid name
    }
    for (int i = 0; i < len; i++) // Traverse each character
    {
        if (temp_name[i] >= 'A' && temp_name[i] <= 'Z' || temp_name[i] >= 'a' && temp_name[i] <= 'z' || temp_name[i] == ' ') // Check alphabet or space
        {
            continue; // Continue checking
        }
        else
        {
            printf("Error Message: Name must contain only alphabets\n"); // Display error

            return 0; // Invalid name
        }
    }

    return 1; // Name is valid
}

int validatePhone(AddressBook *addressBook, char temp_phone[]) // Function to validate phone number
{
    int len = strlen(temp_phone); // Calculate phone number length
    for (int i = 0; i < len; i++) // Traverse each digit
    {
        if (temp_phone[i] >= '0' && temp_phone[i] <= '9') // Check digit
            continue;
        else
        {
            printf("Error Message: Phone number must contain digits\n"); // Display error
            return 0;                                                    // Invalid phone
        }
    }
    if (len != 10) // Check phone number length
    {
        printf("Error Message: Phone number must contain exactly 10 digits\n"); // Display error
        return 0;
    }
    else if (temp_phone[0] < '6') // Check first digit
    {
        printf("Error Message: 1st Number should between 6 and 9\n"); // Display error
        return 0;
    }
    else
    {
        for (int i = 0; i < addressBook->contactCount; i++) // Check duplicate phone numbers
        {
            if (strcmp(addressBook->contacts[i].phone, temp_phone) == 0) // Compare with existing contacts
            {
                printf("Error Message: Phone Number Must be Unique\n"); // Display error
                return 0;
            }
        }
        return 1; // Phone number is valid
    }
}

int validateEmail(AddressBook *addressBook, char email[]) // Function to validate email address
{
    int i;
    int atCount = 0, dotCount = 0; // Count '@' and '.'
    int atPos = -1, dotPos = -1;   // Store positions of '@' and '.'

    // Character validation
    for (i = 0; email[i] != '\0'; i++) // Traverse email
    {
        if ((email[i] >= 'a' && email[i] <= 'z') ||
            (email[i] >= '0' && email[i] <= '9')) // Allow lowercase letters and digits
        {
            continue;
        }
        else if (email[i] == '@') // Check '@'
        {
            atCount++;
            atPos = i;
        }
        else if (email[i] == '.') // Check '.'
        {
            dotCount++;
            dotPos = i;
        }
        else
        {
            printf("Error: Email must contain lowercase\n"); // Invalid character
            return 0;
        }
    }

    if (atCount == 0) // Check missing '@'
    {
        printf("Error: Missing @\n");
        return 0;
    }

    if (atCount > 1) // Check multiple '@'
    {
        printf("Error: Multiple @ symbols are not allowed\n");
        return 0;
    }

    if (dotCount != 1) // Check exactly one '.'
    {
        printf("Error: Email must contain exactly one '.'\n");
        return 0;
    }

    if (dotPos < atPos) // Ensure '.' comes after '@'
    {
        printf("Error: Dot must appear after @\n");
        return 0;
    }

    if (dotPos == atPos + 1) // Ensure at least one character between '@' and '.'
    {
        printf("Error: There must be at least one character between @ and .\n");
        return 0;
    }

    // Must end with .com
    if (strcmp(email + dotPos, ".com") != 0) // Validate domain
    {
        printf("Error: Extra characters after the domain\n");
        return 0;
    }

    // Duplicate email check
    for (i = 0; i < addressBook->contactCount; i++) // Check duplicate emails
    {
        if (strcmp(addressBook->contacts[i].email, email) == 0) // Compare with existing emails
        {
            printf("Error: Email already exists\n");
            return 0;
        }
    }

    return 1; // Email is valid
}

void createContact(AddressBook *addressBook) // Function to create a new contact
{
    /* Define the logic to create a Contacts */
    int num = 1, yon = 0;              // Loop control variables
    int i = addressBook->contactCount; // Store current contact index
    do
    {
        if (addressBook->contactCount < MAX_CONTACTS) // Check maximum contact limit
        {

            char temp_name[50]; // Temporary name buffer
            int ret = 1;        // Validation status
            while (ret)         // Repeat until valid name
            {
                printf("Enter the name :\n");  // Prompt for name
                scanf(" %[^\n]", temp_name);   // Read name
                ret = validateName(temp_name); // Validate name
                if (ret == 0)
                {
                    ret = 1; // Continue on invalid input
                    // num=1;
                    continue;
                }
                else
                {
                    strcpy(addressBook->contacts[i].name, temp_name); // Store valid name
                    // num=0;
                    break;
                }
            }
            while (ret) // Repeat until valid phone number
            {
                printf("Enter the Phone:\n");                 // Prompt for phone
                char temp_phone[20];                          // Temporary phone buffer
                scanf(" %[^\n]", temp_phone);                 // Read phone
                ret = validatePhone(addressBook, temp_phone); // Validate phone
                if (ret == 0)
                {
                    ret = 1; // Continue on invalid input
                    // num=1;
                    continue;
                    // break;
                }
                else
                {
                    strcpy(addressBook->contacts[i].phone, temp_phone); // Store valid phone
                    // num=0;
                    break;
                }
            }

            while (ret) // Repeat until valid email
            {
                printf("Enter the Email\n");                  // Prompt for email
                char temp_email[50];                          // Temporary email buffer
                scanf(" %[^\n]", temp_email);                 // Read email
                ret = validateEmail(addressBook, temp_email); // Validate email
                if (ret == 0)
                {
                    ret = 1; // Continue on invalid input
                    // num=1;
                    continue;
                    // break;
                }
                else
                {
                    strcpy(addressBook->contacts[i].email, temp_email); // Store valid email
                    addressBook->contactCount++;                        // Increment contact count
                    printf("You want to save another contact\n");       // Ask user to continue
                    printf("1.Yes\n2.No\n");
                    scanf("%d", &yon); // Read user's choice
                    if (yon == 1)
                        num = 1; // Continue adding contacts
                    else
                        num = 0; // Exit contact creation
                    break;
                }
            }
        }
        else
        {
            printf("Max contact is exceeded\n"); // Maximum limit reached
        }
        // saveAndExit(addressBook,i);
    } while (num); // Repeat until user chooses to stop
}

void searchContact(AddressBook *addressBook) // Function to search contacts
{
    /* Define the logic for search */
    int searchBy = 0, num = 0; // Variables for search option and loop control
    char temp_name[20];        // Buffer to store entered name
    char temp_phone[20];       // Buffer to store entered phone number
    char temp_email[50];       // Buffer to store entered email
    do                         // Repeat until user exits
    {
        printf("Search by \n1.Name\n2.Phone\n3.Email\n4.Exit\n"); // Display search menu
        scanf("%d", &searchBy);                                   // Read search option
        switch (searchBy)                                         // Perform action based on user's choice
        {
        case 1:
            printf("Enter Name: "); // Prompt for name
            scanf("%s", temp_name); // Read name
            printf("\n");
            int k = 0, ret = 0; // Loop counter and match flag

            for (k = 0; k < addressBook->contactCount; k++) // Traverse all contacts
            {
                if (strcasestr(addressBook->contacts[k].name, temp_name) == 0) // Check for matching name
                {
                    // ret=0;
                    continue; // Continue if not matched
                }
                else
                {
                    printf("%d\t%s\t%s\t%s\n", k + 1, addressBook->contacts[k].name, addressBook->contacts[k].phone, addressBook->contacts[k].email); // Display matched contact
                    ret = 1;                                                                                                                          // Match found
                }
            }
            printf("\n");
            if (ret == 0) // No match found
            {
                printf("No Matching Name Record found,Try Again\n");
                // num=1;
            }

            break;

        case 2:
            printf("Enter Phone: "); // Prompt for phone
            scanf("%s", temp_phone); // Read phone
            printf("\n");

            for (k = 0; k < addressBook->contactCount; k++) // Traverse contacts
            {
                if (strcasestr(addressBook->contacts[k].phone, temp_phone) == 0) // Check matching phone
                {
                    // ret=0;
                    continue;
                }
                else
                {
                    printf("%d\t%s\t%s\t%s\n", k + 1, addressBook->contacts[k].name, addressBook->contacts[k].phone, addressBook->contacts[k].email); // Display contact
                    ret = 1;                                                                                                                          // Match found
                }
            }
            printf("\n");
            if (ret == 0) // No phone matched
            {
                printf("No Matching Phone Record found,Try Again\n");
                // num=1;
            }
            break;

        case 3:
            printf("Enter Email: "); // Prompt for email
            scanf("%s", temp_email); // Read email
            printf("\n");
            for (k = 0; k < addressBook->contactCount; k++) // Traverse contacts
            {
                if (strcasestr(addressBook->contacts[k].email, temp_email) == 0) // Check matching email
                {
                    // ret=0;
                    continue;
                }
                else
                {
                    printf("%d\t%s\t%s\t%s\n", k + 1, addressBook->contacts[k].name, addressBook->contacts[k].phone, addressBook->contacts[k].email); // Display contact
                    ret = 1;                                                                                                                          // Match found
                }
            }
            printf("\n");
            if (ret == 0) // No email matched
            {
                printf("No Matching Emial Record found,Try Again\n");
                // num=1;
            }
            break;

        case 4:
            searchBy = 4;        // Set exit condition
            printf("Exiting\n"); // Display exit message
            break;

        default:
            printf("Enter valid search creteria\n"); // Invalid menu choice
            // num=1;
        }
    } while (searchBy != 4); // Continue until Exit is selected
}

void editContact(AddressBook *addressBook) // Function to edit contact details
{
    int searchBy = 0, num = 0, count = 0, choose = 0, exitstatus = 1, yon = 0; // Control variables
    int m = addressBook->contactCount;                                         // Store contact count
    char temp_name[20];                                                        // Buffer for name
    char temp_phone[20];                                                       // Buffer for phone
    char temp_email[50];                                                       // Buffer for email
    int displayindex[100];                                                     // Stores matching contact indices
    do
    {
        printf("Search by \n1.Name\n2.Phone\n3.Email\n4.Exit\n"); // Display edit menu
        scanf("%d", &searchBy);                                   // Read option
        switch (searchBy)
        {
        case 1:
            int k = 0, ret = 1;                // Loop counter and validation flag
            printf("Enter the name to edit:"); // Prompt for name
            scanf(" %[^\n]", temp_name);       // Read name

            for (k = 0; k < addressBook->contactCount; k++) // Search matching contacts
            {
                if (strcasestr(addressBook->contacts[k].name, temp_name))
                {
                    displayindex[count] = k; // Store matched index
                    count++;
                }
            }

            if (count == 0) // No match found
            {
                printf("No Contact found\n");
                num = 1;
            }
            else
            {
                while (exitstatus) // Repeat until valid edit
                {
                    for (int i = 0; i < count; i++) // Display matched contacts
                    {
                        printf("%d\t%s\t%s\t%s\n", i + 1, addressBook->contacts[displayindex[i]].name, addressBook->contacts[displayindex[i]].phone, addressBook->contacts[displayindex[i]].email);
                    }
                    printf("Choose the contact to edit:"); // Prompt for selection
                    scanf("%d", &choose);

                    if (choose > count) // Validate selected index
                    {
                        printf("\nError message :choose the valid contact index\n");
                        exitstatus = 1;
                    }
                    else
                    {
                        char edit_name[30]; // Buffer for new name
                        while (ret)
                        {
                            printf("Enter the name to Edit: ");
                            scanf(" %[^\n]", edit_name);
                            ret = validateName(edit_name); // Validate name
                            if (ret == 0)
                            {
                                ret = 1;
                                continue;
                            }
                            else
                            {
                                strcpy(addressBook->contacts[displayindex[choose - 1]].name, edit_name); // Update name
                                printf("Edit of Name is done....\n");
                                exitstatus = 0;
                                break;
                            }
                        }
                    }
                }
            }

            count = 0; // Reset match count
            printf("Want to edit anohter contact\n1.Yes\n2.No\n");
            scanf("%d", &yon); // Read user's choice

            if (yon == 1)
            {
                num = 1;
                exitstatus = 1;
            }
            else
                num = 0;

            break;

        case 2:
            k = 0, ret = 1; // Reset variables
            printf("Enter the phone number to edit:");
            scanf(" %[^\n]", temp_phone);

            for (k = 0; k < addressBook->contactCount; k++) // Search by phone
            {
                if (strstr(addressBook->contacts[k].phone, temp_phone))
                {
                    displayindex[count] = k;
                    count++;
                }
            }

            if (count == 0)
            {
                printf("No Contact found\n");
                num = 1;
            }
            else
            {
                while (exitstatus)
                {
                    for (int i = 0; i < count; i++) // Display matches
                    {
                        printf("%d\t%s\t%s\t%s\n", i + 1, addressBook->contacts[displayindex[i]].name, addressBook->contacts[displayindex[i]].phone, addressBook->contacts[displayindex[i]].email);
                    }

                    printf("Choose the contact to edit:");
                    scanf("%d", &choose);

                    if (choose > count)
                    {
                        printf("\nError message :choose the valid contact index\n");
                        exitstatus = 1;
                    }
                    else
                    {
                        char edit_phone[30]; // Buffer for new phone
                        while (ret)
                        {
                            printf("Enter the phone number to Edit: ");
                            scanf(" %[^\n]", edit_phone);
                            ret = validatePhone(addressBook, edit_phone); // Validate phone

                            if (ret == 0)
                            {
                                ret = 1;
                                continue;
                            }
                            else
                            {
                                strcpy(addressBook->contacts[displayindex[choose - 1]].phone, edit_phone); // Update phone
                                printf("Edit of phone is done....\n");
                                exitstatus = 0;
                                break;
                            }
                        }
                    }
                }
            }

            count = 0;
            printf("Want to edit anohter contact\n1.Yes\n2.No\n");
            scanf("%d", &yon);

            if (yon == 1)
            {
                num = 1;
                exitstatus = 1;
            }
            else
                num = 0;

            break;

        case 3:
            k = 0, ret = 1; // Reset variables
            printf("Enter the Email to edit:");
            scanf(" %[^\n]", temp_email);

            for (k = 0; k < addressBook->contactCount; k++) // Search by email
            {
                if (strstr(addressBook->contacts[k].email, temp_email))
                {
                    displayindex[count] = k;
                    count++;
                }
            }

            if (count == 0)
            {
                printf("No Contact found\n");
                num = 1;
            }
            else
            {
                while (exitstatus)
                {
                    for (int i = 0; i < count; i++) // Display matches
                    {
                        printf("%d\t%s\t%s\t%s\n", i + 1, addressBook->contacts[displayindex[i]].name, addressBook->contacts[displayindex[i]].phone, addressBook->contacts[displayindex[i]].email);
                    }

                    printf("Choose the contact to edit:");
                    scanf("%d", &choose);

                    if (choose > count)
                    {
                        printf("\nError message :choose the valid contact index\n");
                        exitstatus = 1;
                    }
                    else
                    {
                        char edit_email[30]; // Buffer for new email
                        while (ret)
                        {
                            printf("Enter the Email to Edit: ");
                            scanf(" %[^\n]", edit_email);
                            ret = validateEmail(addressBook, edit_email); // Validate email

                            if (ret == 0)
                            {
                                ret = 1;
                                continue;
                            }
                            else
                            {
                                strcpy(addressBook->contacts[displayindex[choose - 1]].email, edit_email); // Update email
                                printf("Edit of Email is done....\n");
                                exitstatus = 0;
                                break;
                            }
                        }
                    }
                }
            }

            count = 0;
            printf("Want to edit anohter contact\n1.Yes\n2.No\n");
            scanf("%d", &yon);

            if (yon == 1)
            {
                num = 1;
                exitstatus = 1;
            }
            else
                num = 0;

            break;

        case 4:
            num = 0; // Exit editing
            printf("Exiting\n");
            break;

        default:
            printf("\nEnter the valid choice"); // Invalid choice message
        }
    } while (num); // Repeat if user wants to edit another contact
}

void deleteContact(AddressBook *addressBook) // Function to delete a contact
{
    /* Define the logic for deletecontact */
    int searchBy, count = 0, choice; // Variables for search option, match count, and selected contact
    char temp_name[50];              // Buffer to store entered name
    char temp_phone[20];             // Buffer to store entered phone number
    char temp_email[50];             // Buffer to store entered email
    int displayIndex[100];           // Stores indices of matched contacts

    printf("Delete Contact By\n"); // Display delete menu
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("4. Exit\n");
    scanf("%d", &searchBy); // Read user's choice

    switch (searchBy) // Perform search based on selected option
    {
    case 1:
        printf("Enter Name : ");     // Prompt for name
        scanf(" %[^\n]", temp_name); // Read name

        for (int i = 0; i < addressBook->contactCount; i++) // Search matching names
        {
            if (strcasestr(addressBook->contacts[i].name, temp_name))
            {
                displayIndex[count++] = i; // Store matched contact index
            }
        }
        break;

    case 2:
        printf("Enter Phone : "); // Prompt for phone number
        scanf("%s", temp_phone);  // Read phone number

        for (int i = 0; i < addressBook->contactCount; i++) // Search matching phone numbers
        {
            if (strcmp(addressBook->contacts[i].phone, temp_phone) == 0)
            {
                displayIndex[count++] = i; // Store matched contact index
            }
        }
        break;

    case 3:
        printf("Enter Email : "); // Prompt for email
        scanf("%s", temp_email);  // Read email

        for (int i = 0; i < addressBook->contactCount; i++) // Search matching emails
        {
            if (strcmp(addressBook->contacts[i].email, temp_email) == 0)
            {
                displayIndex[count++] = i; // Store matched contact index
            }
        }
        break;

    case 4:
        return; // Exit delete function

    default:
        printf("Invalid Choice\n"); // Invalid menu option
        return;
    }

    if (count == 0) // Check if no matching contacts found
    {
        printf("Contact Not Found\n");
        return;
    }

    for (int i = 0; i < count; i++) // Display all matched contacts
    {
        printf("%d\t%s\t%s\t%s\n", i + 1, addressBook->contacts[displayIndex[i]].name, addressBook->contacts[displayIndex[i]].phone, addressBook->contacts[displayIndex[i]].email);
    }

    printf("Choose Contact to Delete : "); // Prompt user to choose contact
    scanf("%d", &choice);                  // Read selected contact

    if (choice < 1 || choice > count) // Validate selected contact
    {
        printf("Invalid Choice\n");
        return;
    }

    int deleteIndex = displayIndex[choice - 1]; // Get actual contact index to delete

    int yon;                                  // Variable for confirmation
    printf("Are you sure?\n1. Yes\n2. No\n"); // Ask for confirmation
    scanf("%d", &yon);                        // Read confirmation

    if (yon != 1) // Cancel deletion if user selects No
    {
        printf("Delete Cancelled\n");
        return;
    }

    for (int i = deleteIndex; i < addressBook->contactCount - 1; i++) // Shift contacts to fill deleted position
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--; // Reduce total contact count

    printf("Contact Deleted Successfully\n"); // Display success message
}