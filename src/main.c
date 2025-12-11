#include <stdio.h>
#include <stdlib.h>
#include "contacts.h"
#include "file_io.h"

void show_menu() {
    printf("\n=== Contact Manager ===\n");
    printf("1. Add Contact\n");
    printf("2. List All Contacts\n");
    printf("3. Show Contact by ID\n");
    printf("4. Update Contact\n");
    printf("5. Delete Contact\n");
    printf("6. Exit\n");
    printf("Choice: ");
}

int main() {
    create_directory();
    load_contacts();
    
    int choice;
    while (1) {
        show_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                list_contacts();
                break;
            case 3: {
                int id;
                printf("Enter ID: ");
                scanf("%d", &id);
                int index = get_contact_by_id(id);
                if (index != -1) {
                    printf("\nID: %d\n", ids[index]);
                    printf("Name: %s %s\n", first_names[index], last_names[index]);
                    printf("Phone: %s\n", phone_numbers[index]);
                    printf("Email: %s\n", emails[index]);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 4:
                update_contact();
                break;
            case 5:
                delete_contact();
                break;
            case 6:
                save_contacts();
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
