#include <iostream>
#include "ItemToPurchase.h"
using namespace std;

int main() {
    // Declare two ItemToPurchase objects
    ItemToPurchase item1, item2;
    string name;
    int price, quantity;

    // Enter information for the first item 
    cout << "Item 1" << endl;

    // Prompt user for item name
    cout << "Enter the item name:\n";
    getline(cin, name);           // Use getline to read full string (with spaces)
    item1.SetName(name);          // Set name to item1

    // Prompt user for item price
    cout << "Enter the item price:\n";
    cin >> price;
    item1.SetPrice(price);        // Set price to item1

    // Prompt user for item quantity
    cout << "Enter the item quantity:\n";
    cin >> quantity;
    item1.SetQuantity(quantity);  // Set quantity to item1

    cin.ignore(); // Ignore leftover newline in buffer before next getline()

    // Enter information for the second item 
    cout << "\nItem 2" << endl;

    // Prompt user for item name
    cout << "Enter the item name:\n";
    getline(cin, name);
    item2.SetName(name);

    // Prompt user for item price
    cout << "Enter the item price:\n";
    cin >> price;
    item2.SetPrice(price);

    // Prompt user for item quantity
    cout << "Enter the item quantity:\n";
    cin >> quantity;
    item2.SetQuantity(quantity);

    // Display total cost
    cout << "\nTOTAL COST\n";

    // Print cost details for item1
    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $"
         << item1.GetPrice() << " = $"
         << item1.GetPrice() * item1.GetQuantity() << endl;

    // Print cost details for item2
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $"
         << item2.GetPrice() << " = $"
         << item2.GetPrice() * item2.GetQuantity() << endl;

    // Calculate and print total cost
    int total = item1.GetPrice() * item1.GetQuantity()
              + item2.GetPrice() * item2.GetQuantity();
    cout << "\nTotal: $" << total << endl;

    return 0;
}
