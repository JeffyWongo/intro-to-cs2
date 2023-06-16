#include <iostream>
#include "IntVector.h"
using namespace std;

int main() 
{
    IntVector test(5, 1);
    if(test.size() != 5)
    {
        cout << "FAILED .size() function" << endl;
    }

    if(test.capacity() != 5)
    {
        cout << "FAILED .capacity() function" << endl;
    }

    IntVector test2;
    if(!test2.empty())
    {
        cout << "FAILED .empty() function" << endl;
    }

    if(test.at(2) != 1)
    {
        cout << "FAILED .at() function" << endl;
    }

    if(test.front() != 1)
    {
        cout << "FAILED .front() function" << endl;
    }

    if(test.back() != 1)
    {
        cout << "FAILED .back() function" << endl;
    }

    return 0;
}