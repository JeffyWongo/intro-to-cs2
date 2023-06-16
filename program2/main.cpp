#include "ShoppingCart.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


void printMenu(ShoppingCart cart)
{
    string itemname;
    char choice;
    cout << "MENU" << endl
    << "a - Add item to cart" << endl
    << "d - Remove item from cart" << endl
    << "c - Change item quantity" << endl
    << "i - Output items' descriptions" << endl
    << "o - Output shopping cart" << endl
    << "q - Quit" << endl << endl << "Choose an option: " << endl;
    cin >> choice;
    while(choice != 'q')
    {
        if (choice == 'a') 
        {
            ItemToPurchase item;
            cin.ignore();
            cout << endl << "ADD ITEM TO CART" << endl;
            string itemname;
            string itemdescription;
            int itemprice;
            int itemquantity;

            cout << "Enter the item name: ";
            getline(cin, itemname); 
            item.setName(itemname);

            cout << endl << "Enter the item description: ";
            getline(cin, itemdescription);
            item.setDescription(itemdescription);

            cout << endl << "Enter the item price: ";
            cin >> itemprice;
            item.setPrice(itemprice);

            cout << endl << "Enter the item quantity: ";
            cin >> itemquantity;
            item.setQuantity(itemquantity);
            cart.addItem(item);
            cout << endl << endl;
            cout << "MENU" << endl
            << "a - Add item to cart" << endl
            << "d - Remove item from cart" << endl
            << "c - Change item quantity" << endl
            << "i - Output items' descriptions" << endl
            << "o - Output shopping cart" << endl
            << "q - Quit" << endl << endl << "Choose an option: " << endl;
            cin >> choice;
        }    
        else if (choice == 'd') 
        {
            cout << endl << "REMOVE ITEM FROM CART" << endl;
            cin.ignore();
            cout << "Enter name of item to remove: " << endl;
            getline(cin, itemname);
            cart.removeItem(itemname);
            cout << endl << "MENU" << endl
            << "a - Add item to cart" << endl
            << "d - Remove item from cart" << endl
            << "c - Change item quantity" << endl
            << "i - Output items' descriptions" << endl
            << "o - Output shopping cart" << endl
            << "q - Quit" << endl << endl << "Choose an option: " << endl;
            cin >> choice;
        }    
        else if (choice == 'c') 
        {
            ItemToPurchase newItem;
            int newQuantity;
            cin.ignore();
            cout << endl << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: " << endl;
            getline(cin, itemname);
            cout << "Enter the new quantity: " << endl;
            cin >> newQuantity;
            newItem.setQuantity(newQuantity);
            newItem.setName(itemname);
            cart.modifyItem(newItem);
            cout << endl << "MENU" << endl
            << "a - Add item to cart" << endl
            << "d - Remove item from cart" << endl
            << "c - Change item quantity" << endl
            << "i - Output items' descriptions" << endl
            << "o - Output shopping cart" << endl
            << "q - Quit" << endl << endl << "Choose an option: " << endl;
            cin >> choice;
        }    
        else if (choice == 'i') 
        {
            cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cart.printDescriptions();
            cout << endl;
            cout << "MENU" << endl
            << "a - Add item to cart" << endl
            << "d - Remove item from cart" << endl
            << "c - Change item quantity" << endl
            << "i - Output items' descriptions" << endl
            << "o - Output shopping cart" << endl
            << "q - Quit" << endl << endl << "Choose an option: " << endl;
            cin >> choice;
        }    
        else if (choice == 'o') 
        {
            cout << endl << "OUTPUT SHOPPING CART" << endl;
            cart.printTotal();
            cout << endl;
            cout << "MENU" << endl
            << "a - Add item to cart" << endl
            << "d - Remove item from cart" << endl
            << "c - Change item quantity" << endl
            << "i - Output items' descriptions" << endl
            << "o - Output shopping cart" << endl
            << "q - Quit" << endl << endl << "Choose an option: " << endl;
            cin >> choice;
        }    
        else if (choice == 'q')
        {
            exit(1);
        }
        else
        {
            cout << "Choose an option: " << endl;
            cin >> choice;
        }
    }
}

int main()
{
    string name;
    string date;
    cout << "Enter customer's name: " << endl;
    getline(cin, name);
    cout << "Enter today's date: " << endl;
    getline(cin, date);
    cout << endl << "Customer name: " << name << endl;
    cout << "Today's date: " << date << endl << endl;
    ShoppingCart cart(name, date);
    printMenu(cart);
    return 0;
}