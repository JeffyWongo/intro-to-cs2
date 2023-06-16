// Parameterized constructor to assign item name, item description, item price, and item quantity (default values of 0).
// Public member functions
//  setDescription() mutator & description() accessor
//  printItemCost() - Outputs the item name followed by the quantity, price, and subtotal
//  printItemDescription() - Outputs the item name and description
// Private data members
//  string _description - Initialized in default constructor to "none"

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include <string>
#include <iostream>
using namespace std;

class ItemToPurchase 
{
    public:
        ItemToPurchase();
        ItemToPurchase(string name, string description, int price, int quantity);
        string name() const;//accessor
        int price() const;//accessor
        int quantity() const;//accessor
        string description() const;//accessor
        void setName(string name);//mutator
        void setPrice(int price);//mutator
        void setQuantity(int quantity);//mutator
        void setDescription(string description); //mutator
        void printItemCost(); // Outputs the item name followed by the quantity, price, and subtotal
        void printItemDescription(); //Outputs the item name and description
        
    private:
        string _name;
        int _price;
        int _quantity;
        string _description;
};

#endif