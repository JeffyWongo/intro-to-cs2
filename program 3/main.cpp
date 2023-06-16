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

    IntVector test3(40, 20);
    if(test3.at(1) != 20)
    {
        cout << "FAILED .at() function" << endl;
    }
    test3.insert(1, 15);
    if(test3.at(1) != 15)
    {
        cout << "FAILED .insert() function" << endl;
    }

    test3.erase(1);
    if(test3.at(1) != 20)
    {
        cout << "FAILED .erase() function" << endl;
    }

    test3.assign(5, 50);
    if(test3.at(2) != 50)
    {
        cout << "FAILED .assign() function" << endl;
    }

    test3.push_back(60);
    if(test3.at(6) != 60)
    {
        cout << "FAILED .push_back() function" << endl;
    }

    test3.pop_back();
    if(test3.size() != 5) 
    {
        cout << "FAILED .pop_back() function" << endl;
    }

    test3.clear();
    if(test3.size() != 0)
    {
        cout << "FAILED .clear() function" << endl;
    }

    test3.resize(10, 100);
    if(test3.size() != 10)
    {
        cout << "FAILED .resize() function" << endl;
    }

    test3.reserve(20);
    if(test3.size() != 20)
    {
        cout << "FAILED .reserve() function" << endl;
    }
    
    return 0;
}