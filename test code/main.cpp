#include <iostream>
using namespace std;
void reverse(int arr[], int n) 
{
   if(n <= 0)
   {
      return;
   }
   else
   {
      reverse(arr + 1, n - 2);
      int temp = arr[0];
      arr[0] = arr[n-1];
      arr[n-1] = temp;
   }
}


int main()
{
   int arr[7] = {1,2,3,4,5,6,7};
   reverse(arr, 7);
   for (int i = 0; i < 7; i++)
   {
      cout << arr[i] << " ";
   }
   return 0;
}