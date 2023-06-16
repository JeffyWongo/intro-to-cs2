#include <iostream>

using namespace std;

int main() {
    int n;
    int d;

    cin >> n;
    cin >> d;
   int gcd = 1;
   int tempnumerator = n;
   int tempdenominator = d;
   
   while (gcd > 0) {
    gcd = tempnumerator % tempdenominator;
    tempnumerator = tempdenominator;
    tempdenominator = gcd;
   }
   
   cout << tempnumerator;
   return 0;
}
