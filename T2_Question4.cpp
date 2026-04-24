#include <iostream>
using namespace std;

void getMinMax(int* p_array, int size, int &a_min, int &a_max);
void showArray(int* p_array, int size);

int main()
{
    int myArray[] = {3, 8, 11, 2};
    int min = 10000, max = 0;

    int numItem = sizeof(myArray)/sizeof(int);

    showArray(myArray, numItem);
    getMinMax(myArray, numItem, min, max);

    cout << "\n The maximum = " << max;
    cout << "\n The minimum = " << min;

    return 0;
}

void getMinMax(int* p_array, int size, int &a_min, int &a_max)
{
    for (int i = 0; i < size; i++)
    {
        if (p_array[i] < a_min)
            a_min = p_array[i];

        if (p_array[i] > a_max)
            a_max = p_array[i];
    }
}

void showArray(int* p_array, int size)
{
    cout << "Value of array\n";
    for (int i = 0; i < size; i++)
    {
        cout << p_array[i] << "   ";
    }
    cout << endl;
}