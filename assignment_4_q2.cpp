#include<iostream>
using namespace std;


class stack{
int size;
int *ptr;
unsigned int top;
//int capacity;

public:
stack(int size=5){

this->size=size;
top=-1;
ptr=new int[size];



}

bool isFull(){

if(size-1==top){
return 1;
}else{return 0;}    
}

bool isemty(){
    if(top==-1){
        return 1;
    }else{return 0;}
}




void push(int item){
    if((isFull())){
        cout<<"stak is full"<<endl;
    }else{
        ptr[++top]=item;
    }

}

void pop(){
    if((isemty())){
        cout<<"stack is emty";
    }else{
        cout<<ptr[top]<<endl;
        top--;
    }


}



void peek(){
    if((isemty())){
        cout<<"stack is emty";
    }else{
        cout<<ptr[top]<<endl;
        top;
    }

}
};

int main(){
stack t1;
t1.push(10);
t1.push(20);
//t1.peek();
t1.pop();
t1.pop();




    return 0;
}







