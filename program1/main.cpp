#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

void readData(const string &inputFile, vector<double> &flightPaths, vector<double> &liftCoefficients) {
   double flightPath;
   double liftCoefficient;
   
   ifstream inFS(inputFile);
   
   if (!inFS.is_open()) {
      cout << "Error opening " << inputFile << endl;
      exit(1);
   }

   while(inFS >> flightPath) {
      flightPaths.push_back(flightPath);
      inFS >> liftCoefficient;
      liftCoefficients.push_back(liftCoefficient);
   }
   inFS.close();
}

double interpolation(double flightPathInput, const vector<double> &flightPaths, vector<double> &liftCoefficients) {
   double liftCoefficientInput;
      if(flightPathInput <= flightPaths.at(flightPaths.size()-1) && flightPathInput >= flightPaths.at(0)) {
         for (unsigned int i = 0; i < flightPaths.size(); i++) {
            if(flightPathInput == flightPaths.at(i)) {
               return liftCoefficients.at(i);
            }
         }
         for(unsigned int i=0; i<flightPaths.size(); i++) {
            if(flightPathInput > flightPaths.at(i) && flightPathInput < flightPaths.at(i+1)) {
               liftCoefficientInput = liftCoefficients.at(i) + ((flightPathInput - flightPaths.at(i)) * (liftCoefficients.at(i+1) - liftCoefficients.at(i)) / (flightPaths.at(i+1) - flightPaths.at(i)));
                  return liftCoefficientInput;
            }
         }
      }
      else {
         cout << "Out of range" << endl;
      }
   return 0;
}

bool isOrdered(const vector<double> &flightPaths) {
   if(flightPaths.empty()) {
      return true;
   }
   for (unsigned int i=0; i<flightPaths.size() - 1; i++) {
      if(flightPaths.at(i) > flightPaths.at(i+1)) {
      return false;
      }
   }
   return true;
}

void reorder(vector<double> &flightPaths, vector<double> &liftCoefficients) {
   double tempnum;
   if(flightPaths.empty()) {
      return;
   }
   for(unsigned int i=0; i<flightPaths.size()-1; ++i) {
      for(unsigned int j=0; j<flightPaths.size()-1; ++j) {
         if(flightPaths.at(j) > flightPaths.at(j+1)) {
            tempnum = flightPaths.at(j);
            flightPaths.at(j) = flightPaths.at(j+1);
            flightPaths.at(j+1) = tempnum;
            tempnum = liftCoefficients.at(j);
            liftCoefficients.at(j) = liftCoefficients.at(j+1);
            liftCoefficients.at(j+1) = tempnum;
         }
      }
   }
}

int main() {
   string inputFile;
   string answer = "Yes";
   double flightPathAngle;
   vector<double> flightPaths;
   vector<double> liftCoefficients;
   ifstream inFS(inputFile);

   cin >> inputFile;
   readData(inputFile, flightPaths, liftCoefficients);

   if(!isOrdered(flightPaths)) {
      reorder(flightPaths, liftCoefficients);
   }
    
   while(answer == "Yes" || answer == "yes") {
      cout << "Requested flight-path angle: ";
      cin >> flightPathAngle;
      cout << interpolation(flightPathAngle, flightPaths, liftCoefficients) << endl;
      cout << "Do you want to enter another flight-path angle?";
      cin >> answer;
   }
    return 0;
}