#include <iostream>
using namespace std;

class Fraction {

    private:
    int numerator;
    int denominator;

    public:
    Fraction() {}
    Fraction( int a_nume, int a_denom) {
        numerator = a_nume;
        denominator = a_denom;
    }
    void display() {
        cout << numerator << "/" << denominator << "\n";
    }
    
    Fraction add(Fraction f) {
        int newNum = (numerator * f.denominator) + (f.numerator * denominator);
        int newDen = denominator * f.denominator;
        return Fraction(newNum, newDen);
    }

    Fraction multiply(Fraction f) {
        int newNum = numerator * f.numerator;
        int newDen = denominator * f.denominator;
        return Fraction(newNum, newDen);
    }
};

int main() {

    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction result;
    
    cout << "f1: ";
    f1.display();
    
    cout << "f2: ";
    f2.display();
    
    cout << "f1 + f2: ";
    result = f1.add(f2);
    result.display();
    
    cout << "f1 * f2: ";
    result = f1.multiply(f2);
    result.display();

    return 0;
}