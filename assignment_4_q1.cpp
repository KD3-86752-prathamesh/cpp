#include<iostream>
using namespace std;

class time{

int h;
int m;
int s;

public:
    time(){
        h=00;
        m=00;
        s=00;
    }
    time(int h,int m,int s){
        this->h=h;
        this->m=m;
        this->s=s;
    }

    void accept(){
        cout<<"enter a hours"<<endl;
        cin>>h;
        cout<<"enter minute"<<endl;
        cin>>m;
        cout<<"enter a secounds"<<endl;
        cin>>s;
    }

    void display(){
        cout<<"time is "<<h<<"/"<<m<<"/"<<s<<endl;

    }


    int gethours(){
        return h;

    }
    int getminute(){
        return m;
    

    }
    int getsecounds(){
        return s;

    }

    void sethours(int h){
         this->s=s;
    }
    void setmints(int m){
        this->m=m;
    }
    void setseconds(int s){
        this->s=s;
    }
    
};

int main(){
    time **ptr = new time*[5];
    ptr[0] = new time(1,2,4);
    ptr[1] = new time(6,9,9);
    ptr[2] = new time(3,4,6);
    ptr[3] = new time(4,5,6);
    ptr[4] = new time(5,7,9);


    for(int i=0;i<5;i++){
        ptr[i]->display();
    }

    delete[]ptr;
    ptr=NULL;
    return 0;

}

