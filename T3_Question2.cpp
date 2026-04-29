#include <iostream>
using namespace std;

// Reference version
void swap(int &num1, int &num2);

// Pointer version
void swap_v2(int *num1, int *num2);

int main() {
    int x = 2, y = 4;

    cout << "Before swap (reference):";
    cout << "\n x = " << x;
    cout << "\n y = " << y;

    swap(x, y);

    cout << "\nAfter swap (reference):";
    cout << "\n x = " << x;
    cout << "\n y = " << y;

    // Reset values
    x = 2;
    y = 4;

    cout << "\n\nBefore swap (pointer):";
    cout << "\n x = " << x;
    cout << "\n y = " << y;

    swap_v2(&x, &y);

    cout << "\nAfter swap (pointer):";
    cout << "\n x = " << x;
    cout << "\n y = " << y;

    return 0;
}

// Reference swap
void swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// Pointer swap
void swap_v2(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}