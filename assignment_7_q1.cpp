 /* Q1. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class 
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books. 
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program 
should be menu driven and should not cause memory leakage.
Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]*/

#include<iostream>
using namespace std;
class Product
{
public:
int id;
string title;
double price;
public:
Product()
{
    id=0;
    title="abc";
    price=10;
}
Product(int id,string title,double price)
{
this->id=id;
this->title=title;
this->price=price;
}

virtual void accept()
{
cout<<"enter the id of product-"<<endl;
cin>>id;
cout<<"enter the title of product-"<<endl;
cin>>title;
cout<<"enter the price of product"<<endl;
cin>>price;
}


virtual void display()
{
cout<<"product id="<<id<<"title"<<title<<"price"<<price<<endl;
}

// virtual double calculatePrice() = 0;

 };


//***********************************************************************

class Book:public Product
{
// int id;
// string title;
string author;
// double price;

public:
Book()
{
    author="a aa";
}
Book(int id,string title,double price,string auther):Product(id,title,price)
{
   this->author;
}

void accept()
{
Product::accept();
cout<<"enter the author-"<<endl;
cin>>author;
}

double calculatediscountPrice(double price)
{ 
    return price-price*.9;
}

void display()
{
Product::display();
cout<<"author id="<<author<<endl;
}

};
//************************************************************


class Tape:public Product
{
// int id;
// string title;
string artist;
// double price;

public:
Tape()
{
    artist="abc";
}
Tape(int id,string title,double price,string artist):Product(id,title,price)
{
    this->artist=artist;

}
 void accept()
{
    Product::accept();
cout<<"enter the artist-"<<endl;
cin>>artist;
}


void dispaly()
{
    Product::display();
cout<<"artist id="<<artist<<endl;
}



};

int main()
{
    int choice;
     Product* arr[3];

     for(int i=0;i<3;i++)
     {
        cout<<"0 for Book"<<endl;
        cout<<"1 for Tape"<<endl;
        cin>>choice;
        if (choice==0)
        {
            arr[i]=new Book;
            arr[i]->accept();
        }
        else if (choice==0)
        {
            arr[i]=new Tape;
            arr[i]->accept();
        }
        else 
        cout<<"wrong choice....";
     }

     for(int i=0;i<3;i++)
    {
        arr[i]->display();
    }
     double total=0;
    double totaldiscount=0;
    double x;
    for(int i=0;i<3;i++)
    {
        if(typeid(arr[i])==typeid(Book))
        {
        x= arr[i]->price;
        total+=x;
        totaldiscount+=x*.90;
        }
        else
        {
        x= arr[i]->price;
        total+=x;
        totaldiscount+=x*.95;
        }

    }
    cout<<"Total Price :"<<total<<endl;
    cout<<"Discounted Price :"<<totaldiscount;
    return 0;

    // do
    // {
    //     cout<<"0.EXIT"<<endl;
    //     cout<<"1.Add product"<<endl;
    //     cout<<"2. show total bill"<<endl;
    //     cout<<"enter your choice"<<endl;
    //     cin>>choice;

    //     switch(choice)
    //     {
    //         case 1:
    //         {
    //         Product *b= new Book();
    //         b->accept();
    //         b->display();
    //         break;
    //         case 3:

    //         int total=0;
    //         int x;

    //         for(int i=0; i<3; i++){
    //         if(typeid(arr[i]) == typeid(Book))
    //         {

    //             x = arr[i]->price;
    //             total += x * 0.95;
    //         }
    //         else 
    //         {
    //             total += x * 0.90;
    //         }
    //         }

    //         }

    //         }

    //     } while (choice!=0);

    // for(int i=0;i<)    
    return 0;
}
