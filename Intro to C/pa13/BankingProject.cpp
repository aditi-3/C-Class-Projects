#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <cmath>
#include <iomanip>
using namespace std;

class Account
{
    private:
        int ID;
        string name;
        string socialSecurity;

    public:
        Account()
        {

        }
        Account(int id, string n, string ss)
        {
            ID = id;
            name = n;
            socialSecurity = ss;
        }

        string getName()
        {
            return name;
        }

        int getID()
        {
            return ID;
        }

        string getSocialSecurity()
        {
            return socialSecurity;
        }

        void setName(string n)
        {
            name = n;
        } 

        void setID(int i)
        {
            ID = i;
        }  

        void setSocialSecurity(int i)
        {
            socialSecurity = i;
        }

};

class Checking: public Account
{
    private:
        double balance = 0;
        int checks = 0;
    public:
        Checking(int id, string n, string ss)
        {
            Account(id, n, ss);
        }

        double getBalance()
        {
            return balance;
        }

        void widthdraw(double i)
        {
            balance = balance - i;
        }

        virtual void deposit(double i)
        {
            balance = balance + i;
        }

        double calculateInterest()
        {
            double interest = balance * 0.025;
            balance = balance + interest;
            return  interest;
        }

        int getChecks()
        {
            balance = balance - 0.10;
            return ++checks;
        }
};

class Savings: public Account
{
    private:
        double balance = 0;
    public: 
        Savings(int id, string n, string ss)
        {
            Account(id, n, ss);
        }

        double getBalance()
        {
            return balance;
        }

        void widthdraw(double i)
        {
            if(balance - i > 25)
            {
                balance = balance - i;
                cout<<"\nDeducted successfully from Savings!";            
            }
            else 
            {
                cout<<"\nInsufficient amount in savings.";
            }
        }

        void deposit(double i)
        {
            balance = balance + i;
        }
 
        double calculateInterest()
        {
            double interest = balance * 0.0375;
            balance = balance + interest;
            return  interest;
        }
};

int main()
{
    string name, ss;
    int id;
    cout<<"\nPlease register with your personal information: \nEnter your full name: ";
    cin>>name;
    cout<<"\nEnter your SSN: ";
    cin>>ss;
    cout<<"\nEnter your account ID: ";
    cin>>id;
    Savings saveAcc = Savings(id, name, ss);
    Checking checkAcc = Checking(id, name, ss);
    string choice = "";
    string openAcc = "";
    string input = "";
    string choice2 = "";
    do //if openAcc != "n"
    {
        cout<<"\n------------------------------------------------------";
        cout<<"\n"<<'\t'<<'\t'<<"Bank Services Menu";
        cout<<"\n"<<'\t'<<'\t'<<"-------------------";
        cout<<"\n"<<'\t'<<'\t'<<"1) Checking Account";
        cout<<"\n"<<'\t'<<'\t'<<"2) Savings Account";
        cout<<"\n"<<'\t'<<'\t'<<"3) End of services";
        cout<<"\n\n"<<'\t'<<'\t'<<"Enter your choice: ";
        cin>>choice;
        cout<<"\nOpen/manage the Checking/Savings account (y/n)? ";
        cin>>openAcc;
        if(choice == "1")
        {
            do //if input != "g"
            {
                cout<<"\n\n"<<'\t'<<'\t'<<"*** Checking ***"<<"\n"<<'\t'<<'\t'<<"Account Activities"<<"\n"<<'\t'<<'\t'<<"==================";
                cout<<"\n"<<'\t'<<'\t'<<" a) ---Deposit----";
                cout<<"\n"<<'\t'<<'\t'<<" b) ---Withdraw---";
                cout<<"\n"<<'\t'<<'\t'<<" c) ---Transfer---";
                cout<<"\n"<<'\t'<<'\t'<<" d) ---Balance----";
                cout<<"\n"<<'\t'<<'\t'<<" e) Personal Check";
                cout<<"\n"<<'\t'<<'\t'<<" f) ---Interest---";
                cout<<"\n"<<'\t'<<'\t'<<" g) -----Done-----";
                cout<<"\n\n"<<'\t'<<'\t'<<"Enter your choice: ";
                cin>>input;
                int amount;
                if(input == "a")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Deposit ***"<<"\n"<<'\t'<<'\t'<<"Enter amount to deposit? ";
                    cin>>amount;
                    checkAcc.deposit(amount);
                    cout<<"\nAdded successfully to Checking!"<<"\nChecking balance: "<<checkAcc.getBalance();
                }
                else if(input == "b")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Withdraw ***"<<"\n"<<'\t'<<'\t'<<"Enter amount to withdraw? ";
                    cin>>amount;
                    checkAcc.widthdraw(amount);
                    cout<<"\nDeducted successfully from Checking!"<<"\nChecking balance: "<<checkAcc.getBalance();
                }
                else if(input == "c")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Transfer ***";
                    cout<<"\n"<<'\t'<<'\t'<<"1) from Checking to Savings";
                    cout<<"\n"<<'\t'<<'\t'<<"2) from Savings to Checking";
                    cout<<"\n\n"<<'\t'<<'\t'<<"Enter your choice: ";
                    cin>>choice2;
                    if(choice2 == "1")
                    {
                        cout<<"\n"<<'\t'<<'\t'<<"Enter amount to transfer? ";
                        cin>>amount;
                        checkAcc.widthdraw(amount);
                        saveAcc.deposit(amount);
                        cout<<"\nDeducted successfully from Checking!\nAdded successfully to Savings!";
                        cout<<"\nChecking balance: "<<checkAcc.getBalance()<<"\nSavings Balance: "<<saveAcc.getBalance();
                    }
                    else if(choice2 == "2")
                    {
                        cout<<"\n\n"<<'\t'<<'\t'<<"Enter amount to transfer? ";
                        cout<<"\n\nCannot process! Invalid order or not enough money.";
                    }
                }
                else if(input == "d")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Balance ***";
                    cout<<"\nChecking balance: "<<checkAcc.getBalance();
                }
                else if(input == "e")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Personal Check ***";
                    cout<<"\n\n"<<'\t'<<'\t'<<"Enter amount to withdraw? ";
                    cin>>amount;
                    checkAcc.widthdraw(amount+15);
                    cout<<"\nDeducted successfully from Checking!"<<"\nYou have written "<<checkAcc.getChecks()<<" check(s)";
                    cout<<"\nChecking balance: "<<checkAcc.getBalance();
                }
                else if(input == "f")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Interest ***";
                    cout<<"\nChecking divident: "<<checkAcc.calculateInterest();
                    cout<<"\nChecking balance: "<<checkAcc.getBalance();
                }
                else if(input == "g")
                {
                        cout<<"\nEnd of checking account option";
                        cout<<"\nNumber of checks signed: "<<checkAcc.getChecks();
                        cout<<"\nChecking divident: $"<<checkAcc.calculateInterest();
                        cout<<"\nChecking balance: $"<<checkAcc.getBalance();
                }
            } while (input != "g");
        } //if (choice == "1")
        else if(choice == "2")
        {
            do
            {
                cout<<"\n\n"<<'\t'<<'\t'<<"*** Savings ***"<<"\n"<<'\t'<<'\t'<<"Account Activities"<<"\n"<<'\t'<<'\t'<<"==================";
                cout<<"\n"<<'\t'<<'\t'<<" a) ---Deposit----";
                cout<<"\n"<<'\t'<<'\t'<<" b) ---Withdraw---";
                cout<<"\n"<<'\t'<<'\t'<<" c) ---Transfer---";
                cout<<"\n"<<'\t'<<'\t'<<" d) ---Balance----";
                cout<<"\n"<<'\t'<<'\t'<<" e) Personal Check";
                cout<<"\n"<<'\t'<<'\t'<<" f) ---Interest---";
                cout<<"\n"<<'\t'<<'\t'<<" g) -----Done-----";
                cout<<"\n\n"<<'\t'<<'\t'<<"Enter your choice: ";
                cin>>input;
                int amount;
                if(input == "a")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Deposit ***"<<"\n"<<'\t'<<'\t'<<"Enter amount to deposit? ";
                    cin>>amount;
                    saveAcc.deposit(amount);    
                    saveAcc.widthdraw(5);
                    cout<<"\nAdded successfully to Savings!"<<"\nSavings balance: "<<saveAcc.getBalance();
                }
                else if(input == "b")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Withdraw ***"<<"\n"<<'\t'<<'\t'<<"Enter amount to withdraw? ";
                    cin>>amount;
                    saveAcc.widthdraw(amount);
                    cout<<"\nSavings balance: "<<saveAcc.getBalance();
                }
                else if(input == "c")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Transfer ***";
                    cout<<"\n"<<'\t'<<'\t'<<"1) from Checking to Savings";
                    cout<<"\n"<<'\t'<<'\t'<<"2) from Savings to Checking";
                    cout<<"\n\n"<<'\t'<<'\t'<<"Enter your choice: ";
                    cin>>choice2;
                    if(choice2 == "2")
                    {
                        cout<<"\n\n"<<'\t'<<'\t'<<"Enter amount to transfer? ";
                        cin>>amount;
                        saveAcc.widthdraw(amount);
                        checkAcc.deposit(amount);
                        saveAcc.widthdraw(1);
                        cout<<"\nDeducted successfully from Savings!\nAdded successfully to Checking!";
                        cout<<"\nChecking balance: "<<checkAcc.getBalance()<<"\nSavings Balance: "<<saveAcc.getBalance();
                    }
                    else if(choice2 == "1")
                    {
                        cout<<"\n\n"<<'\t'<<'\t'<<"Enter amount to transfer? ";
                        cout<<"\n\nCannot process! Invalid order or not enough money.";
                    }
                }
                else if(input == "d")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Balance ***";
                    cout<<"\nChecking balance: "<<checkAcc.getBalance();
                }
                else if(input == "e")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Personal Check ***";
                    cout<<"\n\n"<<'\t'<<'\t'<<"Savings account does not support personal checks.";
                }
                else if(input == "f")
                {
                    cout<<"\n\n"<<'\t'<<'\t'<<"*** Interest ***";
                    cout<<"\nSaving divident: "<<saveAcc.calculateInterest();
                    cout<<"\nSaving balance: "<<saveAcc.getBalance();
                }
                else if(input == "g")
                {
                    cout<<"\nEnd of savings account option";
                    cout<<"\nSaving divident: $"<<checkAcc.calculateInterest();
                    cout<<"\nSaving balance: $"<<checkAcc.getBalance();
                    cout<<"\n\nOpen/manage the Checking/Savings account (y/n)? ";
                    cin>>openAcc;
                }
            } while (input != "g");
        } //else if (choice == "2")
        else
        {
            cout<<"Thanks for visiting our bank, "<< checkAcc.getName()<<"\nWe hope you are happy with us.";
        } //else if (choice == "3")
    } while (choice != "3");
    printf("\nProgrammer: Aditi Verma -- CISC 192 C++ programming");
}