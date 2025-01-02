# management-system
## Overview:
The Inventory Management System is a simple, file-based application written in C that allows users to manage an inventory through basic operations. The system supports adding items, displaying the inventory, searching for items by name, and updating item quantities. All data is stored persistently in a file (inventory.txt) to ensure consistency across sessions.

## Features:
- Add Item: Add a new item to the inventory by specifying its ID, name, quantity, and price. Duplicate IDs are automatically detected and rejected.
- Display All Items: List all inventory items in a well-formatted table, showing ID, name, quantity, and price.
- Search Item by Name: Perform a case-insensitive search for an item by its name and display its details if found.
- Update Item Quantity: Modify the quantity of an existing item by specifying its unique ID.
- Persistent Data Storage: Inventory data is stored in inventory.txt, ensuring it is retained between program executions.

## File Structure
**Source Files**
1- Inventory.c: Implements the core functionality of the system, including the following functions:
   - addItem(): Adds a new item to the inventory.
   - displayItems(): Displays all items in the inventory.
   - searchItem(): Searches for an item by its name.
   - updateQuantity(): Updates the quantity of an item by ID.
2-main.c: Provides a menu-driven interface for user interaction and delegates operations to the appropriate functions in Inventory.c.

**Header Files**
1- inventory.h: Header file containing the "Item" structure and function prototypes.

## How to Compile and Run
### Prerequisites
- A C compiler (e.g., GCC)
- Basic knowledge of using a terminal or command prompt.

### Steps
1- Clone or download the project files.
2- Open a terminal and navigate to the project directory.
3- Compile the program using--> gcc -o inventory main.c inventory.c
4- Run the program using --> ./inventory

## Usage Instructions
1- Upon running the program, you will see a menu with the following options:
   - Add Item
   - Display All Items
   - Search Item by Name
   - Update Item Quantity
   - Exit
2- Choose an option by entering the corresponding number.
3- Follow the prompts for each action.

## Example Operations:
### Add Item
Enter ID: 104
Enter Name: Grapes
Enter Quantity: 60
Enter Price: 2.50
Item added successfully.

### Display All Items
ID    Name       Quantity    Price
-----------------------------------
101   Apple      50          1.25
102   Banana     100         0.75
103   Orange     75          1.10
104   Grapes     60          2.50

### Search Item
Enter Name to Search: Orange
Found: ID=103, Name=Orange, Quantity=75, Price=1.10

### Update Quantity
Enter ID to Update: 101
Enter New Quantity: 60
Quantity updated successfully.

### Exit the program
Enter your choice: 5
Exiting the program.

## Error Handling
- File Errors: Proper error messages are displayed if the file cannot be opened, read, or written.
- Duplicate IDs: The system checks for duplicate IDs when adding new items and prevents duplication.
- Invalid Input: Handles invalid user input with appropriate messages.

## Assumptions and Limitations
### Assumptions
- The inventory file (inventory.txt) is created automatically if it does not exist.
- The program assumes valid input from the user (e.g., correct data types and formats).

### Limitations
- Limited to 100 items due to the MAX_ITEMS constant.