#include<iostream>
using namespace std ; 

struct Date { 
    int day ; 
    int month ;
    int year ; 

    void initDate() {

        
        day = 1; 
        month = 1 ;
        year = 1900 ; 
    }

    void printDateOnConsole(){
        printf("%d/%d/%d\n" , day , month ,  year);
    }

    void acceptDateFromConsole() {
        printf ("enter day , month and year : "); 
        scanf("%d%d%d", &day , &month , &year ); 
    }

    bool isLeapYear (int year) {
        if (year/4 == 0) 
        {
            printf ("%d" , year , " is a leap year" ) ;
        }
        else if (year/100==0 and year/400 != 0) {
            printf ("%d" , year , " is a leap year");
        }
        else if(year/400 == 0 ){
            printf ("%d" , year , " is a leap");
        }
        else{
            printf("%d" , year , " is not a leap year") ; 
        }
        
    }
};



class date  { 
    public : 
int day ; 
int month ; 
int year ; 

void initDate() {
    day = 1 ; 
    month = 1 ; 
    year = 1900 ; 

}
void printDateOnConsole(){
    cout << day << "/" << month << "/" << year << endl; 
}

void acceptDateFromConsole(){
    cout << "Enter day, month, and year: ";
    cin>> day >> month >> year ; 
} 

bool isLeapYear (int year) {
        if (year/4 == 0) 
        {
            printf ("%d" , year , " is a leap year" ) ;
        }
        else if (year/100==0 and year/400 != 0) {
            printf ("%d" , year , " is a leap year");
        }
        else if(year/400 == 0 ){
            printf ("%d" , year , " is a leap");
        }
        else{
            printf("%d" , year , " is not a leap year") ; 
        }
        
    }

};
int main () { 
    struct Date d1 ; 
    // d1.initDate () ;  // we need to initialize this first to  allocate values to the day month and year 
    // d1.printDateOnConsole () ; 

    // d1.acceptDateFromConsole() ; 
    // d1.printDateOnConsole () ;
    // d1.isLeapYear(d1.isLeapYear) ; 


    date dt1 ; 
    dt1.initDate();
    dt1.printDateOnConsole() ; 
    dt1.acceptDateFromConsole() ; 
    dt1.printDateOnConsole() ;
    dt1.isLeapYear(dt1.year) ;  
    }