# contact-manager - CLI Application

 This Contact Manager is a CLI application developed as part of the ATA Software Engineering Course. It demonstrates fundamental programming concepts including modular programming, array manipulation, file I/O operations, and CSV data handling in C.

The application allows users to manage contact information through a simple menu-driven interface, with all data persistently stored in a CSV file.

 #  Features
- Add Contact  - Create new contact entries with auto-generated IDs
-  List Contacts  - View all contacts in a formatted table
-  Search by ID - Find and display specific contact details
-  Update Contact  - Modify existing contact information
-  Delete Contact  - Remove contacts from the system
-  Persistent Storage  - Data saved to CSV file automatically on exit
-  Error Handling  - Graceful handling of invalid inputs
 
 # Team Members
# MEMBER 1: Aliyah  Adeyemi-Salami
- **[Team Member 2]** - [Student ID] - [GitHub Username]
- **[Team Member 3]** - [Student ID] - [GitHub Username]

# Data Structures
  - `first_names[500][50]`
  - `last_names[500][50]`
  - `emails[500][100]`
  - `phone_numbers[500][20]`
  - `ids[500]`

# Libraries Used
- `stdio.h` - Standard input/output
- `stdlib.h` - Standard library functions
- `string.h` - String manipulation
 
# Storage
- Location: `~/.local/share/contact_manager/contacts.csv`
- Format: CSV (Comma-Separated Values)
- Structure: `id,first_name,last_name,phone_number,email`

#  Installation & Setup

# Prerequisites
bash

# GCC Compiler
sudo apt-get update
sudo apt-get install build-essential

# Git (for cloning)
sudo apt-get install git

# Clone the Repository
bash
git clone https://github.com/yourusername/contact_manager.git
cd contact_manager

# How to Compile

# Manual Compilation
bash
gcc -Iinclude -Wall -o contact_manager src/main.c src/file_io.c src/contacts.c

# How to Run
After successful compilation:

bash
./contact_manager

The program will:
1. Create `~/.local/share/contact_manager/` directory if it doesn't exist
2. Load existing contacts from `contacts.csv` 
3. Display the main menu

# Usage Guide
   Menu Options
 Contact Manager
1. Add Contact
2. List All Contacts
3. Show Contact by ID
4. Update Contact
5. Delete Contact
6. Exit
Choice: 

# 1. Adding a Contact
Choice: 1
 Add New Contact 
First Name: Aliyah
Last Name: Deyemi
Phone Number: 08023764543
Email: liyah@mail.com

Contact added successfully! ID: 1

# 2. Listing All Contacts
Choice: 2

ID    | First Name      | Last Name       | Phone           | Email
-----------------------------------------------------------------------------
1     |  Aliyah| Deyemi         |     08023764543  | john@mail.com
2     | Maryam         | Ali            | 08098765432     | mary@yahoo.com


# 3. Show Contact by ID
Choice: 3
Enter ID: 1

ID: 1
Name: Aliyah Deyemi
Phone:  08023764543
Email:  liyah@mail.com

# 4. Update Contact
Choice: 4
Enter contact ID to update: 1

  Current Contact 
ID: 1
Name:   Aliyah Deyemi
Phone:  08023764543
Email:   liyah@mail.com

  Enter New Information  
First Name: Jonathan
Last Name:  Parker
Phone Number: 08046443944
Email: jonathan@gmail.com

Contact updated successfully!
 
# 5. Delete Contact
Choice: 5
Enter contact ID to delete: 2

Contact deleted successfully!
 
# 6. Exit
Choice: 6
Contacts saved successfully!
Goodbye!

# Descriptions

main.c
- Entry point of the application
- Menu-driven interface
- User input handling
- Program flow control

contacts.c / contacts.h
- Contact management functions
- Add, list, search, update, delete operations
- Array manipulation and data validation

file_io.c / file_io.h
- CSV file operations
- Load contacts from file on startup
- Save contacts to file on exit
- Directory creation and management

# Data Storage

# Storage Location
~/.local/share/contact_manager/contacts.csv

# File Format
csv
id,first_name,last_name,phone_number,email
1,John,Doe,08012345678,john@mail.com
2,Mary,Ada,08098765432,mary@site.com
3,Peter,Pan,08011223344,peter@neverland.com


 
 

 

 
 

 

 

 

 
