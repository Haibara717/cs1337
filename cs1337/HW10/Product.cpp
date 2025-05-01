#include <iostream>
#include "Product.h"
using namespace std;

// Sets all product attributes
void Product::setProductAttributes(string pluInput, string nameInput, int typeInput, double priceInput, int inventoryInput) 
{
    PLU = pluInput;
    name = nameInput;
    type = typeInput;
    price = priceInput;
    inventory = inventoryInput;
}

// Sets the inventory value
void Product::setInventory(int inv)
{
    inventory = inv;
}

// Returns the product PLU code
string Product::getPLU() const
{
    return PLU;
}

// Returns the product name
string Product::getName() const
{
    return name;
}

// Returns the product type (0 = unit, 1 = pound)
int Product::getType() const
{
    return type;
}

// Returns the product price
double Product::getPrice() const
{
    return price;
}

// Returns the current inventory
int Product::getInventory() const
{
    return inventory;
}
