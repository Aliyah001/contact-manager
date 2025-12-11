#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_CONTACTS 500
#define MAX_NAME 50
#define MAX_EMAIL 100
#define MAX_PHONE 20

// Global arrays (declare as extern)
extern char first_names[MAX_CONTACTS][MAX_NAME];
extern char last_names[MAX_CONTACTS][MAX_NAME];
extern char emails[MAX_CONTACTS][MAX_EMAIL];
extern char phone_numbers[MAX_CONTACTS][MAX_PHONE];
extern int ids[MAX_CONTACTS];
extern int contact_count;

// Function declarations
void list_contacts();
void add_contact();
void delete_contact();
void update_contact();
int get_contact_by_id(int id);

#endif
