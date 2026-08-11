# 📇 Address Book

A menu-driven **Address Book application developed in C** for managing contact information. The project supports creating, searching, editing, deleting, sorting, and permanently storing contacts using a CSV file.

## 🚀 Features

* Create new contacts
* Search contacts by:

  * Name
  * Phone number
  * Email
* Edit existing contact details
* Delete contacts with confirmation
* List all contacts
* Sort contacts by:

  * Name
  * Phone number
  * Email
* Validate contact names
* Validate 10-digit phone numbers
* Check duplicate phone numbers
* Validate email addresses
* Check duplicate email addresses
* Save contacts to a CSV file
* Load existing contacts when the application starts

## 🛠️ Technologies Used

* **Programming Language:** C
* **Data Structures:** Structures
* **File Handling:** CSV file operations
* **String Handling:** C string functions
* **Algorithms:** Bubble Sort
* **Concepts:** Pointers, Functions, Structures, Arrays, Validation

## 📂 Project Structure

```text
Address-Book/
│
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── contacts.csv
└── README.md
```

## ⚙️ How It Works

The application starts by initializing the Address Book and loading previously saved contacts from `contacts.csv`.

The user can then select an operation from the main menu:

```text
1. Create Contact
2. Search Contact
3. Edit Contact
4. Delete Contact
5. List All Contacts
6. Exit
```

When the user exits, the current contacts are written to the CSV file for persistent storage.

## 🔐 Input Validation

The application validates contact information before storing it.

### Name

* Minimum length is checked
* Only alphabetic characters and spaces are accepted

### Phone Number

* Must contain digits
* Must contain exactly 10 digits
* First digit must be between 6 and 9
* Duplicate phone numbers are rejected

### Email

* Validates the `@` symbol
* Validates the `.` character
* Checks the position of `@` and `.`
* Requires a `.com` ending
* Duplicate email addresses are rejected

## 🔎 Search

Contacts can be searched using:

```text
Name
Phone
Email
```

The program searches through the stored contacts and displays matching records.

## ✏️ Edit

Existing contacts can be modified by searching using:

* Name
* Phone
* Email

The selected contact can then be updated with validated information.

## 🗑️ Delete

Contacts can be searched and selected for deletion.

The application asks for confirmation before removing the selected contact.

## 📊 Sorting

The project uses **Bubble Sort** to arrange contacts according to:

* Name
* Phone number
* Email

## 💾 File Handling

Contact information is stored in:

```text
contacts.csv
```

The application writes contact information in CSV format:

```text
Name,Phone,Email
```

Contacts are loaded from the CSV file when the program starts and saved when the application exits.

## ▶️ Compilation

Using GCC:

```bash
gcc main.c contact.c file.c -o addressbook
```

Run the program:

### Linux / macOS

```bash
./addressbook
```

### Windows

```bash
addressbook.exe
```

## 🖥️ Sample Output

```text
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit

Enter your choice: 1

Enter Name         : Luffy
Enter Phone Number : 9191919191
Enter Email        : onepeice1@gmail.com

Contact Created Successfully
```

## 📚 Concepts Demonstrated

This project helped implement and strengthen practical C programming concepts including:

* Structures
* Arrays
* Pointers
* Functions
* Header files
* String handling
* File handling
* Input validation
* Searching
* Sorting
* Modular programming

## 🔮 Future Improvements

* Improve email validation to support more valid email formats
* Add password-protected contact storage
* Add contact groups/categories
* Improve CSV parsing for more complex data
* Add a graphical user interface
* Replace Bubble Sort with a more efficient sorting algorithm for larger datasets

## 👨‍💻 Author

**Jayanth Kumar**

ECE Graduate | Embedded Systems Enthusiast | C Programmer
