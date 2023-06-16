#include <iostream>

using namespace std;


int main()
{
    double *ptr, x[6] = {1.5, 2.2, 4.3, 7.5, 9.1, 10.5};
    x = &x[2];
    return 0;
}