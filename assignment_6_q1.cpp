#include <iostream>
#include <string>
using namespace std;

// Date Class
class Date {
private:
    int day, month, year;

public:
    // Constructor for Date
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    // Display Date
    void displayDate() const {
        cout << day << "/" << month << "/" << year;
    }
};

// Person Class
class Person {
protected:
    string name;
    string address;
    Date birthDate;  // Birthdate is an object of type Date

public:
    // Constructor for Person
    Person(string n, string addr, Date bDate) : name(n), address(addr), birthDate(bDate) {}

    // Display Person Details
    void displayPerson() const {
        cout << "Name: " << name << "\nAddress: " << address << "\nBirth Date: ";
        birthDate.displayDate();
        cout << endl;
    }
};

// Employee Class inheriting from Person
class Employee : public Person {
private:
    int id;
    double salary;
    string department;
    Date joiningDate;  // Joining date is an object of type Date

public:
    // Constructor for Employee
    Employee(int empId, double empSalary, string dept, Date joinDate, string empName, string empAddr, Date birthDate)
        : Person(empName, empAddr, birthDate), id(empId), salary(empSalary), department(dept), joiningDate(joinDate) {}

    // Display Employee Details
    void displayEmployee() const {
        displayPerson();  // Display Person's details
        cout << "Employee ID: " << id << "\nSalary: $" << salary << "\nDepartment: " << department
             << "\nJoining Date: ";
        joiningDate.displayDate();
        cout << endl;
    }
};

// Main function to test the implementation
int main() {
    Date birthDate(12, 5, 1995);
    Date joiningDate(1, 1, 2020);

    Employee emp(1, 50000.0, "IT", joiningDate, "John Doe", "123 Main St", birthDate);

    emp.displayEmployee();

    return 0;
}
