#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Structure to hold student data
struct Student
{
    string name;    // Student name
    int idNum;      // Student ID
    int *tests;     // Pointer to dynamically allocated test scores array
    double average; // Average test score
    char grade;     // Course grade
};

// Function prototypes
Student *getData(ifstream &file, int &studentCnt, int &testsCnt);
void calcAverage(Student students[], int studentCnt, int testsCnt);
char getLetterGrade(double avg);
void displayReport(Student students[], int studentCnt);
void cleanupMemory(Student students[], int studentCnt);

int main()
{
    ifstream inputFile("grades.txt"); // File containing student data
    if (!inputFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int studentCnt, testsCnt;
    Student *students = getData(inputFile, studentCnt, testsCnt); // Read data from file
    inputFile.close();

    if (!students)
    {
        cerr << "Failed to allocate memory for students." << endl;
        return 1;
    }

    calcAverage(students, studentCnt, testsCnt); // Compute averages and grades
    displayReport(students, studentCnt);         // Display report
    cleanupMemory(students, studentCnt);         // Free dynamically allocated memory

    return 0;
}

// Function to read student data from a file and allocate memory dynamically
Student *getData(ifstream &file, int &studentCnt, int &testsCnt)
{
    file >> studentCnt >> testsCnt; // Read header values

    Student *students = new Student[studentCnt]; // Allocate memory for student records
    if (!students)
        return nullptr;

    for (int i = 0; i < studentCnt; i++)
    {
        file >> students[i].name >> students[i].idNum; // Read name and ID
        students[i].tests = new int[testsCnt];         // Allocate memory for test scores

        for (int j = 0; j < testsCnt; j++)
        {
            file >> students[i].tests[j]; // Read test scores
        }
    }
    return students;
}

// Function to calculate the average test score and assign a grade
void calcAverage(Student students[], int studentCnt, int testsCnt)
{
    for (int i = 0; i < studentCnt; i++)
    {
        int sum = 0;
        for (int j = 0; j < testsCnt; j++)
        {
            sum += students[i].tests[j]; // Sum test scores
        }
        students[i].average = static_cast<double>(sum) / testsCnt; // Compute average
        students[i].grade = getLetterGrade(students[i].average);   // Assign grade
    }
}

// Function to determine letter grade based on average score
char getLetterGrade(double avg)
{
    if (avg >= 91)
        return 'A';
    if (avg >= 81)
        return 'B';
    if (avg >= 71)
        return 'C';
    if (avg >= 61)
        return 'D';
    return 'F';
}

// Function to display formatted student report
void displayReport(Student students[], int studentCnt)
{
    cout << left << setw(12) << "Student ID" << setw(10) << "Name"
         << setw(10) << "Avg Score" << setw(6) << "Grade" << endl;
    cout << "-----------------------------------------" << endl;

    for (int i = 0; i < studentCnt; i++)
    {
        cout << setw(12) << students[i].idNum
             << setw(10) << students[i].name
             << setw(10) << fixed << setprecision(2) << students[i].average
             << setw(6) << students[i].grade << endl;
    }
}

// Function to deallocate dynamically allocated memory
void cleanupMemory(Student students[], int studentCnt)
{
    for (int i = 0; i < studentCnt; i++)
    {
        delete[] students[i].tests; // Free memory for test scores
    }
    delete[] students; // Free memory for student array
}
