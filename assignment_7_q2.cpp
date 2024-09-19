

    #include<iostream>
    using namespace std;
    
    enum AccountType
    {
        Savings=1,
        checking=2,
        Business=3
    };
//*******************************************************************
    class InsufficientFundsException
    {
        public:
        string message;

        public:
        InsufficientFundsException()
        {
            cout<<"default exception"<<endl;
        }

        InsufficientFundsException(const string message)
        {
            this->message=message;
        }
        void display() const
        {
            cout<<message<<endl;

        }
    };

//***********************************************************************
    class BankAccount
    {
    int accno;
    AccountType type;;
    double balance;

    public:
    BankAccount()
    {
    cout<<"parameterless"<<endl;
    }
    BankAccount(int accno,AccountType type,double balance)
    {
    this->accno=accno;
    this->type=type;
    this->balance=balance;
    }

//************************************
    void accept()
    {
    int choice;

    cout<<"1.savings"<<endl;
    cout<<"2.current"<<endl;
    cout<<"3.Dmat"<<endl;
    cout<<"enter your choice of account"<<endl;
    cin>>choice;
    type=AccountType(choice);
    }
//***************************************
    void display()
    {
    switch(type)
    {
    case Savings:
        cout<<"Account Type=savings"<<endl;
        break;
    case checking:
        cout<<"Account Type=current"<<endl;
        break;
    case Business:
        cout<<"Account Type=business"<<endl;
        break;
    }
    }
//****************************************
    void deposit(double amount)
    {
    if(amount<0)
    {
        throw InsufficientFundsException("deposit amt cannot be negative");
    }
    balance=balance+amount;
    cout<<"balance="<<balance<<endl;
    }
//*****************************************
    void withdraw(double amount)
    {
    if(amount>balance)
    {
        throw InsufficientFundsException("amount cannot be greater than balance");
    }
    balance=balance-amount;
    cout<<"balance="<<balance<<endl;
    }

    };

//***********************************************************************

    int main()
    {
        try                        //try catch exception to catch the exception handling case in file
        {
            {
                // BankAccount acc(12345,Savings,5000.00);
                // acc.display();

                // acc.deposit(500);
                // acc.display();

                // acc.withdraw(60000);
                // acc.display();

                BankAccount acc1(123456,Savings,5000.00);
                acc1.display();

                acc1.deposit(2000);
                acc1.display();

            }
        }
        catch(const InsufficientFundsException &e)
        {
            e.display();
        }
        
        
        return 0;
    }