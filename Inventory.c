#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

/*function allows the user to add a new item to the inventory*/
void addItem() {
    /*Open the file in append mood to add new items*/
    FILE *file = fopen(FILENAME, "a+"); 
    if (!file) {
        perror("Error opening file");
        return;
    }

    Item newItem;

    /*Prompt User for New Item Details*/
    printf("Enter ID: ");
    scanf("%d",&newItem.id);
    printf("Enter Name: ");
    scanf("%s",&newItem.name);
    printf("Enter Quantity: ");
    scanf("%d",&newItem.quantity);
    printf("Enter Price: ");
    scanf("%f",&newItem.price);

    Item temp;

    /*Check for Duplicate ID*/
    while (fscanf(file, "%d,%49[^,],%d,%f\n", &temp.id, temp.name, &temp.quantity, &temp.price) == 4) {
        if (temp.id == newItem.id) {
            printf("Error: Duplicate ID detected.\n");
            fclose(file);
            return;
        }
    }

    /*Write the New Item to the File*/
    fprintf(file, "%d,%s,%d,%.2f\n", newItem.id, newItem.name, newItem.quantity, newItem.price);
    printf("Item added successfully.\n");

    /*Close the file*/
    fclose(file);

}

/*Function is responsible for reading the contents of the inventory file and displaying the items stored in it.*/
void displayItems() {
    /*Opens the file in read-only mode*/
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("\nID\tName\t	Quantity\tPrice\n");
    printf("----------------------------------------------\n");

    Item temp;
    while (fscanf(file, "%d,%49[^,],%d,%f\n", &temp.id, temp.name, &temp.quantity, &temp.price) == 4) {
        printf("%d\t%-10s\t%d\t	%.2f\n", temp.id, temp.name, temp.quantity, temp.price);
    }

    fclose(file);
}

/*function allows the user to search for an item in the inventory by its name.*/
void searchItem() {
    /*Opens the file in read-only mode*/
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    /*Buffer to store the name input by the user*/
    char searchName[MAX_NAME_LENGTH];
    printf("Enter Name to Search: ");
    scanf("%s", searchName);

    Item temp;
    int found = 0;
    /*Iterates through the file to find a matching name*/
    while (fscanf(file, "%d,%49[^,],%d,%f\n", &temp.id, temp.name, &temp.quantity, &temp.price) == 4) {
        if (strcasecmp(temp.name, searchName) == 0) {
            printf("Found: ID=%d, Name=%s, Quantity=%d, Price=%.2f\n", temp.id, temp.name, temp.quantity, temp.price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found.\n");
    }

    fclose(file);
}
/*Function is responsible for modifying the quantity of an existing inventory item identified by its unique ID*/
void updateQuantity() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
/*Array to store inventory items*/
Item items[MAX_ITEMS];  
int count = 0;

/*Read all items from the file*/ 
while (fscanf(file, "%d,%49[^,],%d,%f\n", &items[count].id, items[count].name, 
              &items[count].quantity, &items[count].price) == 4) {
    count++;
    if (count >= MAX_ITEMS) {
        printf("Error: Maximum inventory size exceeded. Increase MAX_ITEMS if needed.\n");
        fclose(file);
        return;
    }
}
fclose(file);

int updateId, newQuantity;
printf("Enter ID to Update: ");
scanf("%d", &updateId);
printf("Enter New Quantity: ");
scanf("%d", &newQuantity);

int found = 0;

/*Search for the item by ID*/
for (int i = 0; i < count; i++) {
    if (items[i].id == updateId) {
        items[i].quantity = newQuantity;
        found = 1;
        break;
    }
}

if (!found) {
    printf("Item with ID %d not found.\n", updateId);
    return;
} 
else {
    /*Rewrite the file with updated data*/
    file = fopen(FILENAME, "w");
    if (!file) {
       perror("Error opening file for writing");
       return;
    }
} 

for (int i = 0; i < count; i++) {
    fprintf(file, "%d,%s,%d,%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
}
fclose(file);

printf("Quantity updated successfully.\n");
}