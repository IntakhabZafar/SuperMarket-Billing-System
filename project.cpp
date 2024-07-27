#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Item {
private:
    string name;
    double price;

public:
    Item(const string& name, double price) : name(name), price(price) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};

class Supermarket {
private:
    map<string, Item> items;
    vector<Item> bucket;
    double totalAmount;
    const double discountThreshold;
    const double discountRate;

public:
    Supermarket() : totalAmount(0.0), discountThreshold(100.0), discountRate(0.1) {}

    void insertItem(const string& name, double price) {
        auto result = items.emplace(name, Item(name, price));
        if (!result.second) {
            cout << "Item '" << name << "' already exists." << endl;
        } else {
            cout << "Item '" << name << "' inserted successfully." << endl;
        }
    }

    void buyItem(const string& name, int quantity) {
        auto it = items.find(name);
        if (it != items.end()) {
            Item item = it->second;
            for (int i = 0; i < quantity; ++i) {
                bucket.push_back(item);
            }
            totalAmount += item.getPrice() * quantity;
            cout << "Added " << quantity << " x '" << name << "' to the bucket." << endl;
        } else {
            cout << "Item '" << name << "' not found." << endl;
        }
    }

    void showBucket() const {
        if (bucket.empty()) {
            cout << "Bucket is empty." << endl;
        } else {
            cout << "Items in the bucket:" << endl;
            for (const Item& item : bucket) {
                cout << item.getName() << ": $" << item.getPrice() << endl;
            }
            cout << "Total amount: $" << totalAmount << endl;
        }
    }

    void applyDiscount() {
        if (totalAmount > discountThreshold) {
            double discount = totalAmount * discountRate;
            totalAmount -= discount;
            cout << "Discount of $" << discount << " applied. New total amount: $" << totalAmount << endl;
        } else {
            cout << "No discount applied. Total amount is below the discount threshold." << endl;
        }
    }

    void generateBill() {
        showBucket();
        applyDiscount();
        cout << "Final amount to be paid: $" << totalAmount << endl;
    }
};

int main() {
    Supermarket supermarket;
    int choice;
    string name;
    double price;
    int quantity;

    while (true) {
        cout << "\nSupermarket Billing System" << endl;
        cout << "1. Insert Item" << endl;
        cout << "2. Buy Item" << endl;
        cout << "3. Show Items in the Bucket" << endl;
        cout << "4. Generate Bill" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter item price: ";
                cin >> price;
                supermarket.insertItem(name, price);
                break;
            case 2:
                cout << "Enter item name: ";
                cin >> name;
                cout << "Enter quantity: ";
                cin >> quantity;
                supermarket.buyItem(name, quantity);
                break;
            case 3:
                supermarket.showBucket();
                break;
            case 4:
                supermarket.generateBill();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;  // Ensure the main function returns an integer
}
