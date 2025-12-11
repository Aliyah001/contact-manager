#include "contacts.h"
#include <stdio.h>
#include <string.h>

// Define the actual arrays
char first_names[MAX_CONTACTS][MAX_NAME];
char last_names[MAX_CONTACTS][MAX_NAME];
char emails[MAX_CONTACTS][MAX_EMAIL];
char phone_numbers[MAX_CONTACTS][MAX_PHONE];
int ids[MAX_CONTACTS];
int contact_count = 0;

void list_contacts() {
    if (contact_count == 0) {
        printf("\nNo contacts found.\n");
        return;
    }
    
    printf("\n%-5s | %-15s | %-15s | %-15s | %-25s\n",
           "ID", "First Name", "Last Name", "Phone", "Email");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < contact_count; i++) {
        printf("%-5d | %-15s | %-15s | %-15s | %-25s\n",
               ids[i], first_names[i], last_names[i],
               phone_numbers[i], emails[i]);
    }
}

int get_contact_by_id(int id) {
    for (int i = 0; i < contact_count; i++) {
        if (ids[i] == id) {
            return i; // Return index
        }
    }
    return -1; // Not found
}

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }
    
    // Generate unique ID
    int new_id = 1;
    if (contact_count > 0) {
        new_id = ids[contact_count - 1] + 1;
    }
    
    printf("\n--- Add New Contact ---\n");
    printf("First Name: ");
    scanf("%49s", first_names[contact_count]);
    
    printf("Last Name: ");
    scanf("%49s", last_names[contact_count]);
    
    printf("Phone Number: ");
    scanf("%19s", phone_numbers[contact_count]);
    
    printf("Email: ");
    scanf("%99s", emails[contact_count]);
    
    ids[contact_count] = new_id;
    contact_count++;
    
    printf("Contact added successfully! ID: %d\n", new_id);
}

void delete_contact() {
    int id;
    printf("Enter contact ID to delete: ");
    scanf("%d", &id);
    
    int index = get_contact_by_id(id);
    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }
    
    // Shift all elements left
    for (int i = index; i < contact_count - 1; i++) {
        ids[i] = ids[i + 1];
        strcpy(first_names[i], first_names[i + 1]);
        strcpy(last_names[i], last_names[i + 1]);
        strcpy(phone_numbers[i], phone_numbers[i + 1]);
        strcpy(emails[i], emails[i + 1]);
    }
    
    contact_count--;
    printf("Contact deleted successfully!\n");
}

void update_contact() {
    int id;
    printf("Enter contact ID to update: ");
    scanf("%d", &id);
    
    int index = get_contact_by_id(id);
    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }
    
    printf("\n--- Current Contact ---\n");
    printf("ID: %d\n", ids[index]);
    printf("Name: %s %s\n", first_names[index], last_names[index]);
    printf("Phone: %s\n", phone_numbers[index]);
    printf("Email: %s\n", emails[index]);
    
    printf("\n--- Enter New Information ---\n");
    printf("First Name: ");
    scanf("%49s", first_names[index]);
    
    printf("Last Name: ");
    scanf("%49s", last_names[index]);
    
    printf("Phone Number: ");
    scanf("%19s", phone_numbers[index]);
    
    printf("Email: ");
    scanf("%99s", emails[index]);
    
    printf("Contact updated successfully!\n");
}
