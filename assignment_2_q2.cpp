#include <iostream> 
using namespace std ; 

class student { 
    public : 
        int rollNo  ; 
    string name ;
    float marks  ;

    void initStudent () { 
        rollNo = 0 ; 
        name = "" ; 
        marks  = 0 ; 
    }

    void printStudentOnConsole() { 
        cout << rollNo <<" | " << name <<" | "<< marks << endl ; 
    }

    void acceptStudentFromConsole () { 
        cout << "Enter rollno , name and marks of student - ";
        cin >> rollNo >> name >> marks ; 
    }

}; 

int main () { 
student s1 ;
    s1.initStudent (); 
    s1.printStudentOnConsole () ; 
    s1.acceptStudentFromConsole() ; 
    s1.printStudentOnConsole () ; 
    
}