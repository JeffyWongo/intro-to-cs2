#include "ShoppingCart.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ShoppingCart cart;
    ItemToPurchase item1;
    ItemToPurchase item2;

    cart.addItem(item1);
    cart.addItem(item2);
    cout << cart.costOfCart() << endl;
    cout << cart.numItemsInCart();

    return 0;
}