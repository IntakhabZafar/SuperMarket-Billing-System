# SuperMarket-Billing-System

Here's a brief description of the C++ code for the supermarket billing system:

### Overview

This C++ program simulates a simple supermarket billing system, allowing users to manage items and generate bills with optional discounts. It involves two main classes: `Item` and `Supermarket`, and provides a menu-driven interface for user interactions.

### Components

1. `Item` Class:
   - **Purpose**: Represents an individual item in the supermarket.
   - **Attributes**:
     - `name`: The name of the item.
     - `price`: The price of the item.
   - **Methods**:
     - Constructor to initialize an item with a name and price.
     - Getter methods to retrieve the item's name and price.

2. `Supermarket` Class:
   - **Purpose**: Manages the inventory and sales processes in the supermarket.
   - **Attributes**:
     - `items`: A map storing items with their names as keys.
     - `bucket`: A vector holding items selected for purchase.
     - `totalAmount`: The total price of items in the bucket.
     - `discountThreshold`: The amount above which a discount is applied.
     - `discountRate`: The discount rate applied if the threshold is exceeded.
   - Methods:
     - `insertItem()`: Adds a new item to the inventory.
     - `buyItem()`: Adds a specified quantity of an item to the bucket and updates the total amount.
     - `showBucket()`: Displays items in the bucket and the total amount.
     - `applyDiscount()`: Applies a discount if the total amount exceeds the discount threshold.
     - `generateBill()`: Shows the bucket’s contents, applies any discount, and prints the final amount.

3. `main()` Function:
   - Provides a menu-driven interface to interact with the `Supermarket` class.
   - Allows the user to insert items, buy items, view the bucket, generate a bill, or exit the program.
   - Uses a loop to repeatedly display the menu and handle user choices until the user decides to exit.

### Key Operations

- **Insert Items**: Users can add new items to the supermarket's inventory.
- **Purchase Items**: Users can select items for purchase, specifying the quantity.
- **View Bucket**: Users can view the list of items in the bucket and the total amount.
- **Generate Bill**: Users can generate a bill, which includes applying discounts if the total amount meets the threshold.

### Usage

- This system is useful for basic inventory and billing management, ideal for small-scale applications or educational purposes. The program’s simplicity makes it a good starting point for understanding how to manage collections of objects and implement basic financial calculations in C++.
