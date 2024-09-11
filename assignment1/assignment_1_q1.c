#include<stdio.h>


struct Date {
    int day;
    int month;
    int year;
};


void initDate(struct Date* ptrDate) {
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 1900;
}


void printDateOnConsole(struct Date* ptrDate) {
    printf("Date: %d/%d/%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}


void acceptDateFromConsole(struct Date* ptrDate) {
    printf("Enter day, month, and year: ");
    scanf("%d%d%d", &ptrDate->day, &ptrDate->month, &ptrDate->year);
}

int main() {
    struct Date d1;  

    initDate(&d1);   
    printDateOnConsole(&d1);  

    acceptDateFromConsole(&d1);  
    printDateOnConsole(&d1); 

    return 0;
}
