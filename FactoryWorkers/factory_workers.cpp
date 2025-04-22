// factory_workers.cpp
#include <iostream>
#include <string>
using namespace std;

// Base class: Employee
class Employee
{
protected:
    string name;
    string employeeNumber;
    string hireDate;

public:
    Employee(string n = "", string empNum = "", string hDate = "")
        : name(n), employeeNumber(empNum), hireDate(hDate) {}

    void setName(string n) { name = n; }
    void setEmployeeNumber(string e) { employeeNumber = e; }
    void setHireDate(string d) { hireDate = d; }

    string getName() const { return name; }
    string getEmployeeNumber() const { return employeeNumber; }
    string getHireDate() const { return hireDate; }

    void printEmployee() const
    {
        cout << "Name: " << name << endl;
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Hire Date: " << hireDate << endl;
    }
};

// Derived class: ProductionWorker
class ProductionWorker : public Employee
{
protected:
    int shift; // 1 for day, 2 for night
    double hourlyPayRate;

public:
    ProductionWorker(string n = "", string e = "", string d = "", int s = 1, double p = 0.0)
        : Employee(n, e, d), shift(s), hourlyPayRate(p) {}

    void setShift(int s) { shift = s; }
    void setHourlyPayRate(double r) { hourlyPayRate = r; }

    int getShift() const { return shift; }
    double getHourlyPayRate() const { return hourlyPayRate; }

    void printProductionWorker() const
    {
        printEmployee();
        cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
        cout << "Hourly Pay Rate: $" << hourlyPayRate << endl;
    }
};

// Derived class: ShiftSupervisor
class ShiftSupervisor : public Employee
{
private:
    double annualSalary;
    double annualBonus;

public:
    ShiftSupervisor(string n = "", string e = "", string d = "", double s = 0.0, double b = 0.0)
        : Employee(n, e, d), annualSalary(s), annualBonus(b) {}

    void setAnnualSalary(double s) { annualSalary = s; }
    void setAnnualBonus(double b) { annualBonus = b; }

    double getAnnualSalary() const { return annualSalary; }
    double getAnnualBonus() const { return annualBonus; }

    void printShiftSupervisor() const
    {
        printEmployee();
        cout << "Annual Salary: $" << annualSalary << endl;
        cout << "Annual Production Bonus: $" << annualBonus << endl;
    }
};

// Derived class: TeamLeader
class TeamLeader : public ProductionWorker
{
private:
    double monthlyBonus;
    int requiredTrainingHours;
    int attendedTrainingHours;

public:
    TeamLeader(string n = "", string e = "", string d = "", int s = 1, double p = 0.0,
               double mb = 0.0, int req = 0, int att = 0)
        : ProductionWorker(n, e, d, s, p), monthlyBonus(mb),
          requiredTrainingHours(req), attendedTrainingHours(att) {}

    void setMonthlyBonus(double b) { monthlyBonus = b; }
    void setRequiredTrainingHours(int h) { requiredTrainingHours = h; }
    void setAttendedTrainingHours(int h) { attendedTrainingHours = h; }

    double getMonthlyBonus() const { return monthlyBonus; }
    int getRequiredTrainingHours() const { return requiredTrainingHours; }
    int getAttendedTrainingHours() const { return attendedTrainingHours; }

    void printTeamLeader() const
    {
        printProductionWorker();
        cout << "Monthly Bonus: $" << monthlyBonus << endl;
        cout << "Required Training Hours: " << requiredTrainingHours << endl;
        cout << "Attended Training Hours: " << attendedTrainingHours << endl;
    }
};

int main()
{
    // Test data
    ProductionWorker pw1("John Doe", "123", "2020-01-15", 1, 20.5);
    ProductionWorker pw2("Jane Smith", "456", "2019-03-22", 2, 22.75);
    ShiftSupervisor ss("Mark Leader", "789", "2018-07-01", 60000, 5000);
    TeamLeader tl("Sara Crew", "321", "2021-06-30", 1, 24.5, 1000, 40, 38);

    cout << "--- Production Worker 1 ---\n";
    pw1.printProductionWorker();
    cout << "\n--- Production Worker 2 ---\n";
    pw2.printProductionWorker();
    cout << "\n--- Shift Supervisor ---\n";
    ss.printShiftSupervisor();
    cout << "\n--- Team Leader ---\n";
    tl.printTeamLeader();

    return 0;
}
