#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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