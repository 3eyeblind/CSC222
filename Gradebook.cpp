#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Global constants
const int MAX_STUDENTS = 100;
const int MAX_TESTS = 5;

// Function prototypes
int readData(ifstream &file, string names[], int scores[][MAX_TESTS]);
void calcAverages(const int scores[][MAX_TESTS], double averages[], int studentCount);
char calcLetterGrade(double average);
void displayReport(const string names[], const double averages[], int studentCount);

int main()
{
    string names[MAX_STUDENTS];
    int scores[MAX_STUDENTS][MAX_TESTS];
    double averages[MAX_STUDENTS];
    int studentCount;

    // Open the input file
    ifstream inputFile("test_scores.txt");
    if (!inputFile)
    {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    // Read data from the file
    studentCount = readData(inputFile, names, scores);
    inputFile.close();

    // Calculate averages
    calcAverages(scores, averages, studentCount);

    // Display the formatted report
    displayReport(names, averages, studentCount);

    return 0;
}

// Function to read data from the file
int readData(ifstream &file, string names[], int scores[][MAX_TESTS])
{
    int studentCount = 0;
    while (file >> names[studentCount])
    { // Read student name
        for (int i = 0; i < MAX_TESTS; i++)
        {
            if (!(file >> scores[studentCount][i]))
            {
                cerr << "Error reading score for " << names[studentCount] << endl;
            }
        }
        studentCount++;
    }
    if (studentCount == 0)
    {
        cerr << "No data found in the file." << endl;
    }
    return studentCount;
}

// Function to calculate averages for each student
void calcAverages(const int scores[][MAX_TESTS], double averages[], int studentCount)
{
    for (int i = 0; i < studentCount; i++)
    {
        int sum = 0;
        for (int j = 0; j < MAX_TESTS; j++)
        {
            sum += scores[i][j];
        }
        averages[i] = static_cast<double>(sum) / MAX_TESTS;
    }
}

// Function to calculate letter grade based on average score
char calcLetterGrade(double average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

// Function to display the formatted report
void displayReport(const string names[], const double averages[], int studentCount)
{
    cout << left << setw(15) << "Name" << setw(10) << "Average" << "Grade" << endl;
    cout << string(30, '-') << endl;

    for (int i = 0; i < studentCount; i++)
    {
        cout << left << setw(15) << names[i]
             << setw(10) << fixed << setprecision(2) << averages[i]
             << calcLetterGrade(averages[i]) << endl;
    }
}
