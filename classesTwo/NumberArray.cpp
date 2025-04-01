#include "NumberArray.h"

NumberArray::NumberArray(int s)
{
    size = s > 0 ? s : MAX_SIZE;
    numbers = new double[size];
    for (int i = 0; i < size; ++i)
    {
        numbers[i] = 0.0;
    }
}

NumberArray::~NumberArray()
{
    cout << "The destructor is running" << endl;
    delete[] numbers;
}

void NumberArray::setNumber(int index, double value)
{
    if (index < 0 || index >= size)
    {
        cout << "The index is out of the bounds of the array, number not stored" << endl;
    }
    else
    {
        numbers[index] = value;
    }
}

double NumberArray::getNumber(int index) const
{
    if (index < 0 || index >= size)
    {
        cout << "The index is out of the bounds of the array, returning default" << endl;
        return DEFAULT_VALUE;
    }
    return numbers[index];
}

double NumberArray::getHighest() const
{
    double max = numbers[0];
    for (int i = 1; i < size; ++i)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    return max;
}

double NumberArray::getLowest() const
{
    double min = numbers[0];
    for (int i = 1; i < size; ++i)
    {
        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }
    return min;
}

double NumberArray::getAverage() const
{
    double sum = 0.0;
    for (int i = 0; i < size; ++i)
    {
        sum += numbers[i];
    }
    return size ? sum / size : 0.0;
}

void NumberArray::print() const
{
    for (int i = 0; i < size; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}