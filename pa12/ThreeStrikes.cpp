#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <cmath>
#include <iomanip>
using namespace std;

//Intricacies of the game setup
class ThreeStrikes
{
    private:
        int price;
        int strikes;
        int digits;

    public:
        ThreeStrikes()
        {
            setPrice(); //random price set
            setDigits(); //digits = 0
            setStrikes(); //strikes = 0
        }

        int getStrikes()
        {
            return strikes;
        }

        int getPrice()
        {
            return price;
        }

        int getDigits()
        {
            return digits;
        }

        void setPrice()
        {
            srand((unsigned) time(NULL));
            price = 10000 + (rand() % 100000);
            cout<<"\n"<<price;
            string check = to_string(price);
            string temp = check.substr(0,1);
            cout<<"\ncheck.substr(i,i+1): "<<check.substr(0,1);
            cout<<"\ntemp: "<<temp;
            for(int i = 0; i < check.length(); i++)
            {
                if(check.substr(i,i+1) == temp)
                {
                    price = 10000 + (rand() % 100000);
                    i = 0;
                    check = to_string(price);
                    temp = check.substr(i,i+1);
                    cout<<"\ncheck.substr(i,i+1): "<<check.substr(i,i+1);
                    cout<<"\ntemp: "<<temp;
                }
            }
        }

        void setStrikes()
        {
            strikes = 0;
        }

        void setDigits()
        {
            digits = 0;
        }

        void strikeIncr() //increment strike value by 1
        {
            strikes++;
        }

        void digitIncr()
        {
            digits ++;
        }
};

//Panel setup
class Panel : public ThreeStrikes
{
    private:
        array<string, 5> panel;
        int index;
        int usedIndexes;
        string p = "";
    
    public:
        Panel()
        {
            setPanel();
            p = to_string(getPrice());
            p += "xxx";
            ThreeStrikes();
        }

        int getIndex()
        {
            return index;
        }

        void setIndex() //Returns one random index from 0-7
        {
            index = 0 + (rand() % 7);  
        }

        void checkIndex()
        {
            if(index <5)
            {
                while(panel[index] != "_")
                {
                    index = 0 + (rand() % 4);
                } 
            }
        }

        string getPanel(int i) //Returns the string of the index from getChipIndex
        {
            if(i < 5)
            {
                return panel[i];
            }
            else{return "null";}
        }
        
        char getPriceAtIndex(int i)
        {
            return p[i];
        }

        void setPanel()  //concatnates the strikes to the price value in a string
        {
            panel = {"_", "_", "_", "_", "_"};
        }

        void incriment(bool x)
        {
            if(x)
            {
                digitIncr();
            }
            else
            {
                strikeIncr();
            }
        }

        bool isDigit(int i)
        {
            if((p[i] != 'x') && i < 5)
            {
                digitIncr();
                //printf("\n\nYou picked a digit!!!");
                return true;
            }
            else
            {
                strikeIncr();
                printf("\n\nYou picked a strike!!!");
                return false;
            }
        }
        void updatePanel(int i) //chip and index for parameter, get parameter using updatePanel(getChip(int), getChipIndex())
        {
            panel[i] = p[i];
        }

        void printPanel()
        {
            string output = "";
            for(int i = 0; i < panel.size(); i++)
            {
                output += panel[i];
                output += " ";
            }
            cout<<"\n"<<'\t'<<"   PANEL: "<<output; 
            cout<<"\n"<<'\t'<<"POSITION: 4 3 2 1 0";
        }

        bool guess(int i)
        {
            if (i==index)
            {
                cout<<"\nCorrect, you picked the correct position!!!";
                return true;
            }
            else
            {
                cout<<"\nSorry! You guessed the wrong position";
                return false;
            }
        }

        bool won()
        {
            bool output = true;
            for(int i = 0; i < panel.size(); i ++)
            {
                if (panel[i] == "_")
                {
                    output = false;
                }   
            }
            return output;
        }
};

//Running game with player
class Game: public Panel
{
    public:
    Game()
    {
        ThreeStrikes();
        Panel(); 
    }
};

int main()
{
    Game player = Game();
    string input = "";   
    cout<<"\n*********** Welcome to Three Strikes Game ***********";
    cout<<"\nPick a chip from a bag, the chip will contain \na digit or a strike, if it's a digit then guess \nwhich position it belongs to the car's price";
    player.printPanel();
    cout<<"\nAccumulating three strikes will result in losing the game.";
    cout<<"\n--------------------------------------------------------------------------";
    cout<<"\nThe price must be hidden: "<<player.getPrice()<<"\n(Shhhh! It's revealed to you as the programmer's darling!!!)";
    cout<<"\n--------------------------------------------------------------------------";
    cout<<"\nEnter 'p' to pick a chip, or any other key to quit the game: ";
    cin>>input;
    cout<<"\n\nStrikes hit: "<<player.getStrikes()<<"\nDigits placed: "<<player.getDigits();
    player.printPanel();        
    while((input != "q") && player.getStrikes() < 3)
    {
        cout<<"\n--------------------------------------------------------------------------";  
        player.setIndex();
        player.checkIndex();
        cout<<"\n.";
        bool isNum = player.isDigit(player.getIndex()); //strike or digit print
        if(isNum)
        {
            if(player.getStrikes() ==3)
            {
                break;
            }
            int in;
            cout<<"\nYou picked the digit: "<<player.getPriceAtIndex(player.getIndex());
            cout<<"\nWhich position do you think it is? ";
            cin>>in;
            if(player.guess(in))
            {
                player.updatePanel(player.getIndex());
                player.printPanel();
            }
        }
        cout<<"\n.";
        if(player.won())
        {
            cout<<"\n\nCongratulations! You won the car!!!";
            cout<<"\nThe price of the car was: $"<<player.getPrice();    
            break;    
        }
        else if(player.getStrikes() == 3)
        {
            cout<<"\n\nSorry, you lost the game!";
            cout<<"\nThe price of the car was: $"<<player.getPrice();
            break;
        }
        cout<<"\n.";
        cout<<"\n\nEnter 'p' to pick a chip, or any other key to quit the game: ";
        cin>>input;
        cout<<"\nStrikes hit: "<<player.getStrikes()<<"\nDigits placed: "<<player.getDigits();
        player.printPanel();
        if(input != "p"){break;}
        cout<<"\n.";
    } 
    printf("\nProgrammer: Aditi Verma -- CISC 192 C++ programming");
}