#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

//setting iten name using SetName function
void ItemToPurchase::SetName(string name) 
{
    itemName = name;
}
//setting iten price using SetPrice function
void ItemToPurchase::SetPrice(int price) 
{
    itemPrice = price;
}
//setting iten quantity using SetQuantity function
void ItemToPurchase::SetQuantity(int quantity) 
{
    itemQuantity = quantity;
}
//returning thhe private member itemName
string ItemToPurchase::GetName() const 
{
    return itemName;
}
//returning thhe private member itemPrice
int ItemToPurchase::GetPrice() const 
{
    return itemPrice;
}
//returning thhe private member itemQuantity
int ItemToPurchase::GetQuantity() const 
{
    return itemQuantity;
}










