#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

// Class definition for ItemToPurchase
class ItemToPurchase {
private:
    // Private data members
    string itemName;     // Name of the item
    int itemPrice;       // Price of the item (in whole dollars)
    int itemQuantity;    // Quantity of the item to purchase

public:
    // Default constructor: sets default values
    ItemToPurchase();

    // Setter (mutator) functions
    void SetName(string name);     // Sets the item name
    void SetPrice(int price);      // Sets the item price
    void SetQuantity(int quantity);// Sets the item quantity

    // Getter (accessor) functions
    string GetName() const;        // Returns the item name
    int GetPrice() const;          // Returns the item price
    int GetQuantity() const;       // Returns the item quantity
};

#endif
