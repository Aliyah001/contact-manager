#include "file_io.h"
#include "contacts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

void create_directory() {
    char path[256];
    snprintf(path, sizeof(path), "%s/.local/share/contact_manager", 
             getenv("HOME"));
    mkdir(path, 0755); // Create if doesn't exist
}

void load_contacts() {
    char filepath[300];
    snprintf(filepath, sizeof(filepath), 
             "%s/.local/share/contact_manager/contacts.csv", 
             getenv("HOME"));
    
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("No existing contacts found. Starting fresh.\n");
        return;
    }
    
    char line[500];
    fgets(line, sizeof(line), file); // Skip header
    
    contact_count = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%49[^,],%49[^,],%19[^,],%99[^\n]",
               &ids[contact_count],
               first_names[contact_count],
               last_names[contact_count],
               phone_numbers[contact_count],
               emails[contact_count]);
        contact_count++;
    }
    
    fclose(file);
    printf("Loaded %d contacts.\n", contact_count);
}

void save_contacts() {
    char filepath[300];
    snprintf(filepath, sizeof(filepath), 
             "%s/.local/share/contact_manager/contacts.csv", 
             getenv("HOME"));
    
    FILE *file = fopen(filepath, "w");
    if (!file) {
        printf("Error saving contacts!\n");
        return;
    }
    
    fprintf(file, "id,first_name,last_name,phone_number,email\n");
    
    for (int i = 0; i < contact_count; i++) {
        fprintf(file, "%d,%s,%s,%s,%s\n",
                ids[i], first_names[i], last_names[i],
                phone_numbers[i], emails[i]);
    }
    
    fclose(file);
    printf("Contacts saved successfully!\n");
}
