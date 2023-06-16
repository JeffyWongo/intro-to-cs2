#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
   int tempnum;
   char comma;
   string inputFile;
   string outputFile;
   vector<int> list;
   unsigned int i;
   int sum = 0;
   int average;

   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
   inputFile = argv[1];
   outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream inFS(inputFile.c_str());
   
   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!inFS.is_open()) {
      cout << "Error opening " << inputFile << endl;
      return 1;
   }
   
   // Read in integers from input file to vector.

   while (inFS >> tempnum) {
      inFS >> comma;
      list.push_back(tempnum);
   }
   
   // Close input stream.
   inFS.close();
   
   for(i=0; i<list.size(); i++) {
      cout << list.at(i); 
   }
// Get integer average of all values read in.
   for (i=0; i < list.size(); i++) {
      sum += list.at(i);
   }
   
   average = (sum / list.size());
   
   // Convert each value within vector to be the difference between the original value and the average.
   for (i=0; i < list.size(); i++) {
      list.at(i) = list.at(i) - average;
   }
   
   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);
   
   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   if (!outFS.is_open()) {
      cout << "Error opening " << outputFile << endl;
      return 1;
   }

   // Write converted values into ouptut csv file, each integer separated by a comma.
   for(i=0; i<list.size(); i++) {
      if(i = list.size()-1) {
         outFS << list.at(i);
      }
      outFS << list.at(i) << ",";
   }
   // Close output stream.
   outFS.close();

   return 0;
}