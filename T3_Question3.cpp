#include <iostream>
#include <ctime>
using namespace std;

void sumAverage(float *pArray, int size, float &a_sum, float &a_average);

int main()
{
    float sum = 0.0, average = 0.0;
    float arrayNum[4] = {1.0, 2.0, 3.0, 4.0};
    int numElem = sizeof(arrayNum) / sizeof(float);
    sumAverage(arrayNum, numElem, sum, average);
    cout << "\n sum = " << sum << " average = " << average;

    return 1;
}

void sumAverage(float *pArray, int size, float &a_sum, float &a_average) {
    a_sum = 0.0;
    for (int i = 0; i < size; i++){
        a_sum += pArray[i];   // or *(pArray + i)
    }

    a_average = a_sum / size;
}