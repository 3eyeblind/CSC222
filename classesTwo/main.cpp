#include <iostream>
#include <iomanip>
#include <random>
#include "NumberArray.h"
using namespace std;

int main()
{
    cout << fixed << setprecision(1);

    cout << "----- Test constructors -----\n\n";
    NumberArray defaultArray;
    cout << "From default constructor: Array of size 10\n";
    defaultArray.print();

    NumberArray customArray(15);
    cout << "\nFrom constructor with parameters: Array of size 15\n";
    customArray.print();

    cout << "\n----- Test mutator -----\n\n";
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1.0, 100.0);

    for (int i = 0; i < 15; ++i)
    {
        customArray.setNumber(i, dis(gen));
    }

    cout << "Array filled with numbers:\n";
    customArray.print();

    cout << "\nTrying to set a number with an out of bounds index (20):\n";
    customArray.setNumber(20, 999.9);

    cout << "\n----- Test accessors -----\n\n";
    cout << "Access item at index 5: " << customArray.getNumber(5) << endl;
    cout << "\nAccess item at index 20 (out of bounds): " << customArray.getNumber(20) << endl;

    cout << "\nThe minimum value in the array is: " << customArray.getLowest() << endl;
    cout << "The maximum value in the array is: " << customArray.getHighest() << endl;
    cout << "The average of the values in the array is: " << customArray.getAverage() << endl;

    return 0;
}