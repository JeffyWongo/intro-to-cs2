#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here
void flipString(string &s)
{
   if(s.size() == 0)
   {
      return;
   }
   else
   {
      string tempstring = s.substr(1);
      flipString(tempstring);
      s = tempstring + s.at(0);
   }
}

