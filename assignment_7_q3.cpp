#include <iostream>
using namespace std;

class Employee {
    int id;
    double salary;

public:
    Employee() {}
    Employee(int id, double salary) : id(id), salary(salary) {}

    virtual void accept() {
        cout << "Enter empid: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void display() {
        cout << "Empid: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual string getDesignation() {
        return "Employee";
    }
};

//************************************************
class Manager : virtual public Employee {
    double bonus;

protected:
    void acceptManager() {
        cout << "Enter bonus: ";
        cin >> bonus;
    }
    void displayManager() {
        cout << "Bonus: " << bonus << endl;
    }

public:
    Manager() {}
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void accept() override {
        Employee::accept();
        acceptManager();
    }

    void display() override {
        Employee::display();
        displayManager();
    }

    string getDesignation() override {
        return "Manager";
    }
};

//*******************************************
class Salesman : virtual public Employee {
    double commission;

protected:
    void acceptSalesman() {
        cout << "Enter commission: ";
        cin >> commission;
    }
    void displaySalesman() {
        cout << "Commission: " << commission << endl;
    }

public:
    Salesman() {}
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void accept() override {
        Employee::accept();
        acceptSalesman();
    }

    void display() override {
        Employee::display();
        displaySalesman();
    }

    string getDesignation() override {
        return "Salesman";
    }
};

//**************************************************
class Salesmanager : public Manager, public Salesman {
public:
    Salesmanager() {}
    Salesmanager(int id, double salary, double bonus, double commission)
        : Employee(id, salary), Manager(id, salary, bonus), Salesman(id, salary, commission) {}

    void accept() override {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display() override {
        Employee::display();
        displayManager();
        displaySalesman();
    }

    string getDesignation() override {
        return "SalesManager";
    }
};

// Main program with menu-driven functionality
int main() {
    int maxEmployees = 100; // maximum number of employees
    Employee** employees = new Employee*[maxEmployees];
    int employeeCount = 0;
    int choice;

    do {
        cout << "\n1. Accept Manager\n2. Accept Salesman\n3. Accept SalesManager\n";
        cout << "4. Display count of all employees by designation\n";
        cout << "5. Display all Managers\n6. Display all Salesmen\n7. Display all SalesManagers\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Employee* emp = nullptr;

        switch (choice) {
            case 1:
                emp = new Manager();
                emp->accept();
                employees[employeeCount++] = emp;
                break;

            case 2:
                emp = new Salesman();
                emp->accept();
                employees[employeeCount++] = emp;
                break;

            case 3:
                emp = new Salesmanager();
                emp->accept();
                employees[employeeCount++] = emp;
                break;

            case 4: {
                int managerCount = 0, salesmanCount = 0, salesmanagerCount = 0;
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i]->getDesignation() == "Manager") managerCount++;
                    else if (employees[i]->getDesignation() == "Salesman") salesmanCount++;
                    else if (employees[i]->getDesignation() == "SalesManager") salesmanagerCount++;
                }
                cout << "Managers: " << managerCount << endl;
                cout << "Salesmen: " << salesmanCount << endl;
                cout << "SalesManagers: " << salesmanagerCount << endl;
                break;
            }

            case 5:
                cout << "Managers: " << endl;
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i]->getDesignation() == "Manager") employees[i]->display();
                }
                break;

            case 6:
                cout << "Salesmen: " << endl;
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i]->getDesignation() == "Salesman") employees[i]->display();
                }
                break;

            case 7:
                cout << "SalesManagers: " << endl;
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i]->getDesignation() == "SalesManager") employees[i]->display();
                }
                break;

            case 8:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    // Cleanup dynamically allocated memory
    for (int i = 0; i < employeeCount; i++) {
        delete employees[i];
    }
    delete[] employees;

    return 0;
}
