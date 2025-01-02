#include "inventory.h"
#include <stdio.h>

int main(){
    /*Is used to store the user's menu selection.*/
    int choice;

    /*Menu Display*/
    do{
        printf("\nMenu:\n");
        printf("1. Add Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by name\n");
        printf("4. Update Item Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                addItem();
                break;
        }

    }while(choice !=5);
    return 0;
}