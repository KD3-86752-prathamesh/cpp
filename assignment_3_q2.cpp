#include <iostream> 
using namespace std ; 

class Tollbooth {
    unsigned int totalCars  ; 
    unsigned int payingCars ; 
    unsigned int nonPayingCars ; 
    double totalCash ; 
    
    public : 
    Tollbooth() {
        totalCars = 0 ;
        payingCars = 0 ; 
        nonPayingCars = 0 ; 
        totalCash = 0 ; 
    }

    void payingCar() {
        totalCars++ ; 
        payingCars++ ; 
        totalCash = totalCash +0.5 ; 

    }

    void nopayCar() {
        totalCars++  ;
        nonPayingCars++ ; 
    }

    void printOnConsole() {
        cout<< "total no of non paying cars : " << nonPayingCars << endl; 
        cout << "total no. of paying cars : " << payingCars << endl ; 
        cout << "total no of cars that passed by : " << totalCars <<endl; 
        cout << "total cash collected : " << totalCash << endl ; 

    }

};


int main () {
    Tollbooth tb  ; 

    tb.nopayCar () ;
    tb.nopayCar () ; 
    tb.payingCar () ;
    tb.payingCar () ; 
    tb.printOnConsole () ; 

}