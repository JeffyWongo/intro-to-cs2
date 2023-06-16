#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &fraction2) const; 
      Rational subtract(const Rational &fraction2) const; 
      Rational multiply(const Rational &fraction2) const; 
      Rational divide(const Rational &fraction2) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here

Rational::Rational() {
   numerator = 0;
   denominator = 1;
}

Rational::Rational(int n) {
   this->numerator = n;
   denominator = 1;
}

Rational::Rational(int n, int d) {
   this->numerator = n;
   this->denominator = d;
}

const Rational Rational::add(const Rational &fraction2) const{
   Rational finalfraction; 
   finalfraction.numerator = ((numerator * fraction2.denominator) + (denominator * fraction2.numerator));
   finalfraction.denominator = (denominator * fraction2.denominator);
   return finalfraction;
}

Rational Rational::subtract(const Rational &fraction2) const {
   Rational finalfraction; 
   finalfraction.numerator = ((numerator * fraction2.denominator) - (denominator * fraction2.numerator));
   finalfraction.denominator = (denominator * fraction2.denominator);
   return finalfraction;
}

Rational Rational::multiply(const Rational &fraction2) const {
   Rational finalfraction;
   finalfraction.numerator = (numerator * fraction2.numerator);
   finalfraction.denominator = (denominator * fraction2.denominator);
   return finalfraction;
}

Rational Rational::divide(const Rational &fraction2) const {
   Rational finalfraction;
   finalfraction.numerator = (numerator * fraction2.denominator);
   finalfraction.denominator = (fraction2.numerator * denominator);
   return finalfraction;
}

void Rational::simplify() {
    int divisor = gcd(numerator, denominator);
    if ((numerator % gcd(numerator, denominator) == 0) && (denominator % gcd(numerator, denominator) == 0)) {
        numerator /= divisor;
        denominator /= divisor;
    }
    else {
        return;
    }
}

void Rational::display() const {
   cout << numerator << " / " << denominator;
}

int Rational::gcd(int n, int d) const {
   int gcd = 1;
   int tempnumerator = n;
   int tempdenominator = d;
   while (gcd > 0) {
      gcd = tempnumerator % tempdenominator;
      tempnumerator = tempdenominator;
      tempdenominator = gcd;
   }
   return tempnumerator;
}





// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

