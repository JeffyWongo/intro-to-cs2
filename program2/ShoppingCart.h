#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream>
#include <string>
#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart 
{
    public:
        ShoppingCart();
        ShoppingCart(string customerName, string currentDate);
        string customerName() const; //accessor
        string date() const; //accessor
        void addItem(ItemToPurchase &item); //mutator
        void removeItem(string &itemname); //mutator
        void modifyItem(const ItemToPurchase &item); // mutator
        int numItemsInCart() const;
        int costOfCart() const;
        void printTotal();
        void printDescriptions();

    private:
        string _customerName;
        string _currentDate;
        vector<ItemToPurchase> _cartItems;
};


#endif

// Build the ShoppingCart class with the following specifications. Note: Some can be function stubs (empty functions) initially, to be completed in later steps.

// Default constructor
// Parameterized constructor which takes the customer name and date as parameters
// Private data members
// string _customerName - Initialized in default constructor to "none"
// string _currentDate - Initialized in default constructor to "January 1, 2016"
// vector < ItemToPurchase > _cartItems
// Public member functions
// customerName() accessor
// date() accessor
// addItem()
// Adds an item to cartItems vector. Has parameter ItemToPurchase. Does not return anything.
// removeItem()
// Removes item from cartItems vector. Has a string (an item's name) parameter. Does not return anything.
// If item name cannot be found, output this message: Item not found in cart. Nothing removed.
// modifyItem()
// Modifies an item's description, price, and/or quantity. Has parameter ItemToPurchase. Does not return anything.
// If item can be found (by name) in cart, check if parameter has default values for description, price, and quantity. If not, modify item in cart.
// If item cannot be found (by name) in cart, output this message: Item not found in cart. Nothing modified.
// numItemsInCart()
// Returns quantity of all items in cart. Has no parameters.
// costOfCart()
// Determines and returns the total cost of items in cart. Has no parameters.
// printTotal()
// Outputs total of objects in cart.
// If cart is empty, output this message: SHOPPING CART IS EMPTY
// printDescriptions()
// Outputs each item's description.