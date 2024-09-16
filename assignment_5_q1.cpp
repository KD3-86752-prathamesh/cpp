#include <iostream> 
using namespace std ;

class Date {
    int day ; 
    int month;
    int year ; 
    public : 
    Date () {
        cout << "inside the date paraless ctor" <<endl; 
        this->day = 0 ; 
        this->month = 0 ; 
        this->year = 0 ; 
    }
    void acceptDate () {
        cout << "enter day:" <<endl; 
        cin >> day ; 
        cout << "enter month:" <<endl; 
        cin>> month ; 
        cout<<"enter year:" <<endl;
        cin >> year ; 
    }

    void displayDate () {
        cout << day << "/" << month << "/" << year ; 
    }
};


class person {
    string name ; 
    string address ; 
    Date birthday ; 
    public :
    person() {
        this->name = "" ; 
        this->address = "" ;
    }

    void acceptperson () {
        cout << "enter person name:" <<endl; 
        cin >> name ; 
        cout << "enter person address:" <<endl;
        cin >> address ;
        cout << "enter birthdate:" <<endl; 
        birthday.acceptDate();
    }

    void displayperson () {
        cout<< "name of peroson : " ;
        cout << name <<endl; 
        cout << "address of person: "  ; 
        cout << address <<endl; 
        cout << "birthdate of person : " ; 
        birthday.displayDate() ; 
    }

};


int main () {
    person p1 ; 
    p1.acceptperson() ;
    p1.displayperson() ; 

}