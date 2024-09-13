#include <iostream>
#include <string>
using namespace std;

class Address {
    string building;
    string street;
    string city;
    int pin;

public:
    // Default constructor
    Address() : building(""), street(""), city(""), pin(0) {}

    // Parameterized constructor
    Address(string bld, string strt, string cty, int pn)
        : building(bld), street(strt), city(cty), pin(pn) {}

    // Getter and Setter for building
    void setBuilding(string bld) {
        building = bld;
    }

    string getBuilding() {
        return building;
    }

    // Getter and Setter for street
    void setStreet(string strt) {
        street = strt;
    }

    string getStreet() {
        return street;
    }

    // Getter and Setter for city
    void setCity(string cty) {
        city = cty;
    }

    string getCity() {
        return city;
    }

    // Getter and Setter for pin
    void setPin(int pn) {
        pin = pn;
    }

    int getPin() {
        return pin;
    }

    // Accept method to input data
    void accept() {
        cout << "Enter building name: ";
        getline(cin, building);
        cout << "Enter street name: ";
        getline(cin, street);
        cout << "Enter city name: ";
        getline(cin, city);
        cout << "Enter pin code: ";
        cin >> pin;
        cin.ignore();  // Clear the input buffer
    }

    // Display method to show data
    void display() {
        cout << "Address Information: " << endl;
        cout << "Building: " << building << endl;
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "Pin: " << pin << endl;
    }
};

int main() {
    // Testing with the default constructor
    Address adr1;
    cout << "Using default constructor and accept method:" << endl;
    adr1.accept();
    adr1.display();

    cout << endl;

    // Testing with the parameterized constructor
    Address adr2("Namdev Bhavan", "MG Road", "Pandharpur", 413304);
    cout << "Using parameterized constructor:" << endl;
    adr2.display();

    // Testing getters and setters
    adr2.setBuilding("New Bhavan");
    adr2.setCity("Pune");
    cout << "\nAfter using setters:" << endl;
    cout << "Updated Building: " << adr2.getBuilding() << endl;
    cout << "Updated City: " << adr2.getCity() << endl;

    return 0;
}
