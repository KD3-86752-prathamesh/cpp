#include <iostream> 
using namespace std; 

class Volume {
public: 
    float length; 
    float width; 
    float height; 

    // Default constructor
    Volume() {
        length = 12; 
        width = 15; 
        height = 10; 

        float vol = length * width * height; 
        cout << "Default volume of the box is - " << vol << endl; 
    }

    // Constructor for a cubical box
    Volume(float parameter) {
        length = parameter; 
        width = parameter; 
        height = parameter; 

        float vol = length * width * height; 
        cout << "Volume of cubical box is - " << vol << endl; 
    }

    // Constructor for a variable-sized box
    Volume(float length, float width, float height) {
        this->length = length; 
        this->width = width; 
        this->height = height; 
        
        float vol = length * width * height; 
        cout << "Volume of the box is - " << vol << endl; 
    }
};

// Function to display the menu and get the user's option
int menu() {
    int option; 
    cout << "\nEnter option:\n";  
    cout << "1. Default volume of the box\n"; 
    cout << "2. Volume of a cubical box\n"; 
    cout << "3. Volume of a variable-sized box\n"; 
    cout << "4. Exit\n"; 
    cin >> option;
    return option; 
}

int main() {
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1: {
                // Create volume object using default constructor
                Volume v1; 
                break;
            }

            case 2: {
                // Create volume object for cubical box
                Volume v2(10); 
                break;
            }

            case 3: {
                // Create volume object for variable-sized box
                Volume v3(10, 12, 13); 
                break; 
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option, please try again.\n";
        }
    } while (choice != 4);

    return 0; 
}
