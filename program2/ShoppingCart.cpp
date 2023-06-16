#include "ShoppingCart.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;


ShoppingCart::ShoppingCart()
{
    _customerName = "none";
    _currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string customerName, string currentDate)
{
    _customerName = customerName;
    _currentDate = currentDate;
}

string ShoppingCart::customerName() const
{
    return _customerName;
}

string ShoppingCart::date() const
{
    return _currentDate;
}

void ShoppingCart::addItem(ItemToPurchase &item)
{
    _cartItems.push_back(item);
}

void ShoppingCart::removeItem(string &itemname)
{
    for(unsigned int i = 0; i < _cartItems.size(); i++)
    {
        if(itemname == _cartItems.at(i).name())
        {
            _cartItems.erase(_cartItems.begin()+i);
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::modifyItem(const ItemToPurchase &item)
{
    ItemToPurchase newItem2;
    for(unsigned int i = 0; i < _cartItems.size(); i++)
    {
        if(item.name() == _cartItems.at(i).name())
        {
            if(item.description() != newItem2.description())
            {
                _cartItems.at(i).setDescription(item.description());
            }
            if(item.price() != newItem2.price())
            {
                _cartItems.at(i).setPrice(item.price());
            }
            if(item.quantity() != newItem2.quantity())
            {
                _cartItems.at(i).setQuantity(item.quantity());
            }
            return;
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl;
}

int ShoppingCart::numItemsInCart() const
{
    int total = 0;
    for(unsigned int i = 0; i < _cartItems.size(); i++)
    {
        total += _cartItems.at(i).quantity();
    }
    return total;
}

int ShoppingCart::costOfCart() const
{
    int total = 0;
    for(unsigned int i = 0; i < _cartItems.size(); i++)
    {
        total += (_cartItems.at(i).price() * _cartItems.at(i).quantity());
    }
    return total;
}

void ShoppingCart::printTotal()
{
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl << endl;
    if (_cartItems.size() == 0)
    {
        cout << "SHOPPING CART IS EMPTY" << endl << endl;
        cout << "Total: $0" << endl;
    }
    else
    {
        for(unsigned int i = 0; i < _cartItems.size(); i++)
        {
            _cartItems.at(i).printItemCost();
        }
        cout << endl << "Total: $" << costOfCart() << endl;
    }
}

void ShoppingCart::printDescriptions()
{
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    for(unsigned int i = 0; i < _cartItems.size(); i++)
    {
        _cartItems.at(i).printItemDescription();
    }
    return;
}
