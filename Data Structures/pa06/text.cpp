#include<iomanip>
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int rafflenum = 1;

typedef struct node
{
    string name;
    int tickr;
    struct node* next;
}node;

node* head = nullptr;

void addname()
{
    node * temp = new node;
    cout<<"Enter name: ";
    cin>>temp->name;
    temp->tickr = rafflenum++;
    temp->next = nullptr;
    if(head == nullptr)
    {
    head = temp;
    return;
    }

    node* temp1 = head;
    while(temp1->next)
    {
    temp1 = temp1->next;
    }
    temp1->next = temp;

}

 

void placeorder()
{

    if(head == nullptr)
    {
    cout<<"Empty queue"<<endl;
    return;
    }
    cout<<head->name<<" can now place an order"<<endl;
    node * temp = head;
    head = head->next;
    delete temp;
}

 

int countnames(node* temp = head)
{
    static int count=0;
    if(temp == nullptr)
    return count;
    count++;
    countnames(temp->next);
}

 

node* locate(node* temp, int winner)
{
    if(temp->tickr == winner)
    {
    return temp;
    }
    if(temp == nullptr)
    return nullptr;
    locate(temp->next, winner);
}

 

void rafflewinner()
{
    srand(time(0));
    int winner = rand()%(rafflenum-1)+1;
    node* ptr = locate(head , winner);
    if(ptr == nullptr)
    {
        cout<<"Person not in queue\n";
        return;
    }

    node* temp = ptr;
    int choice;
    cout<<"Winner is "<<temp->name<<endl;
    cout<<"Choose one of the following:\n"
    <<"1. Go the front of the queue\n"
    <<"2. Get a free T-shirt\n";
    cin>>choice;
    switch (choice)
    {
        case 1:
        {
            cout<<"You are shifted to the front of the row";
            if(temp == head) return;
            node* temp1 = head;
            while(temp1->next != temp)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp->next;
            temp->next = head;
            head = temp;
            break;
        }
    case 2:
        cout<<"You will get a *free t-shirt soon\n";
        break;
    default:
        cout<<"Invalid option\n"
        <<"You have successfully wasted your chance\n";
        break;
    }

}

 

void display()
{
    if(head == nullptr)
    {
        cout<<"Empty queue\n";
        return;
    }

    node* temp = head;
    int pos = 1;
    cout<<" Name Raffle-number Position\n";

    while(temp)
    {
        cout<<setw(6)<<temp->name<<setw(7)<<temp->tickr<<setw(10)<<pos++<<endl;
        temp=temp->next;
    }
}

 

void menu()
{
    cout<<"Menu:\n"
    <<"1. Add a name\n"
    <<"2. Place an order\n"
    <<"3. Count names\n"
    <<"4. Draw raffle winner\n"
    <<"5. Display queue\n"
    <<"6. Exit\n";
}

 

int main()
{
    int choice;
    do
    {
    menu();
    cout<<"Enter choice: ";
    cin>>choice;
        switch (choice)
        {
            case 1:
                addname();
                break;
            case 2:
                placeorder();
                break;
            case 3:
                cout<<"Number of people in the queue: "<<countnames()<<endl;
                break;
            case 4:
                rafflewinner();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                cout<<"Invalid option :: try again\n";
            break;
        }
    }while(true);
}