// inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H
/*Default filename for storing inventory data*/
#define FILENAME "inventory.txt"          
#define MAX_NAME_LENGTH 50

/*Structure representing an inventory item with attributes: ID, name, quantity, and price*/
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

#endif // INVENTORY_H
