#include <iostream>

class Employee {
protected:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}

    void setId(int id) { this->id = id; }
    int getId() const { return id; }

    void setSalary(double salary) { this->salary = salary; }
    double getSalary() const { return salary; }

    virtual void accept() {
        std::cout << "Enter employee ID: ";
        std::cin >> id;
        std::cout << "Enter employee salary: ";
        std::cin >> salary;
    }

    virtual void display() const {
        std::cout << "Employee ID: " << id << std::endl;
        std::cout << "Employee Salary: " << salary << std::endl;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager() : bonus(0) {}
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}

    void setBonus(double bonus) { this->bonus = bonus; }
    double getBonus() const { return bonus; }

    void accept() override {
        Employee::accept();
        std::cout << "Enter manager bonus: ";
        std::cin >> bonus;
    }

    void display() const override { // Corrected signature
        Employee::display();
        std::cout << "Manager Bonus: " << bonus << std::endl;
    }
};

class Salesman : public Employee {
private:
    double commission;

public:
    Salesman() : commission(0) {}
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {}

    void setCommission(double commission) { this->commission = commission; }
    double getCommission() const { return commission; }

    void accept() override {
        Employee::accept();
        std::cout << "Enter salesman commission: ";
        std::cin >> commission;
    }

    void display() const override { // Corrected signature
        Employee::display();
        std::cout << "Salesman Commission: " << commission << std::endl;
    }
};

class SalesManager : public Manager, public Salesman {
public:
    SalesManager() : Manager(), Salesman() {}
    SalesManager(int id, double salary, double bonus, double commission) : Manager(id, salary, bonus), Salesman(id, salary, commission) {}

    void accept() override {
        Manager::accept();
        Salesman::accept();
    }

    void display() const override { // Corrected signature
        Manager::display();
        Salesman::display();
    }
};

int main() {
    Employee employee(101, 50000);
    Manager manager(201, 60000, 10000);
    Salesman salesman(301, 40000, 5000);
    SalesManager salesManager(401, 70000, 15000, 8000);

    employee.accept();
    employee.display();

    manager.accept();
    manager.display();

    salesman.accept();
    salesman.display();

    salesManager.accept();
    salesManager.display();

    return 0;
}