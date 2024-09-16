#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    char gender;
    int rollNumber;
    float marks[3];
    static int rollCounter; // Static member to generate roll numbers

public:
    // Constructor
    Student() {
        rollNumber = ++rollCounter; // Auto-generated roll number
    }

    // Method to input student details
    void inputDetails() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter gender (M/F): ";
        cin >> gender;
        gender = toupper(gender); // Ensure gender is uppercase
        cout << "Enter marks for 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }

    // Method to print student details
    void printDetails() const {
        float percentage = calculatePercentage();
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Gender: " << gender << endl;
        cout << "Percentage: " << fixed << setprecision(2) << percentage << "%" << endl;
    }

    // Method to calculate percentage
    float calculatePercentage() const {
        float total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }
        return (total / 300) * 100; // Assuming each subject is out of 100
    }

    // Get the roll number
    int getRollNumber() const {
        return rollNumber;
    }

    // Get the name
    string getName() const {
        return name;
    }

    // Static method to get the roll number counter
    static int getRollCounter() {
        return rollCounter;
    }
};

// Initialize the static roll number counter
int Student::rollCounter = 0;

// Function to search for a student by roll number
int searchStudent(Student* arr[], int size, int rollNumber) {
    for (int i = 0; i < size; i++) {
        if (arr[i] && arr[i]->getRollNumber() == rollNumber) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int SIZE = 5;
    Student* arr[SIZE] = { nullptr };

    while (true) {
        int choice;
        cout << "\nStudent Management System\n";
        cout << "1. Accept student details\n";
        cout << "2. Print student details\n";
        cout << "3. Search student by roll number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < SIZE; i++) {
                    if (arr[i] == nullptr) {
                        arr[i] = new Student();
                        arr[i]->inputDetails();
                        break;
                    }
                }
                break;
            }

            case 2: {
                for (int i = 0; i < SIZE; i++) {
                    if (arr[i] != nullptr) {
                        arr[i]->printDetails();
                    }
                }
                break;
            }

            case 3: {
                int rollNumber;
                cout << "Enter roll number to search: ";
                cin >> rollNumber;
                int index = searchStudent(arr, SIZE, rollNumber);
                if (index != -1) {
                    arr[index]->printDetails();
                } else {
                    cout << "Student with roll number " << rollNumber << " not found." << endl;
                }
                break;
            }

            case 4: {
                // Clean up dynamically allocated memory
                for (int i = 0; i < SIZE; i++) {
                    delete arr[i];
                }
                return 0;
            }

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
