#include <iostream>

using namespace std;

// Function Prototype
int *ReverseArray(const int arr[], int size);
void print(const int arr[], int size);

int main()
{
    // Define and initialize the original array
    const int SIZE = 10;
    int originalArray[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Display the original array
    cout << "Original array:" << endl;
    print(originalArray, SIZE);

    // Reverse the array
    int *reversedArray = ReverseArray(originalArray, SIZE);

    // Display the reversed array
    cout << "Reversed array:" << endl;
    print(reversedArray, SIZE);

    // Free dynamically allocated memory
    delete[] reversedArray;

    return 0;
}

/**
 * Function: ReverseArray
 * ----------------------
 * This function creates a dynamically allocated array that contains the elements
 * of the input array in reverse order.
 *
 * @param arr  The input array to be reversed.
 * @param size The size of the input array.
 * @return Pointer to the dynamically allocated reversed array.
 */
int *ReverseArray(const int arr[], int size)
{
    // Dynamically allocate memory for the reversed array
    int *reversedArr = new int[size];

    // Copy elements in reverse order
    for (int i = 0; i < size; i++)
    {
        reversedArr[i] = arr[size - 1 - i];
    }

    return reversedArr;
}

/**
 * Function: print
 * ---------------
 * This function prints the contents of an array.
 *
 * @param arr  The input array to be printed.
 * @param size The size of the input array.
 */
void print(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
