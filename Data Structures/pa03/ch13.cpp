/**
 * @name Aditi Verma
 *       ASSIGNMENT 3 - Chapter 13
 * @date 3/13/24
 */

#include <iostream>
using namespace std;

//Prototyping functions
void printMatrix(int *a, int len);
void findInteger(int *a, int len);
void swapCol(int *a, int len);
class dogInventory
{
    private:
        string dogLicense; //<10chars
        string dogName; //<15 chars
        string ownerPhone; //<11 chars
        float priceQuoted; //>= 0 price for bath

    public:
        dogInventory()
        {

        }

        //getters
        string getDogLicense()
        {
            return dogLicense;
        }

        string getGodName()
        {
            return dogName;
        }

        string getOwnerPhone()
        {
            return ownerPhone;
        }

        float getPriceQuoted()
        {
            return priceQuoted;
        }

        //setters
        void setDogLicense(string li)
        {
            dogLicense = li;
        }

        void setGodName(string name)
        {
            dogName = name;
        }

        void setOwnerPhone(string phone)
        {
            ownerPhone = phone;
        }

        void setPriceQuoted(float price)
        {
            priceQuoted = price;
        }
};

int main()
{
    // Initialize array and determine it's number of rows and columns
    int input = 0;

    // Excecute menu until user exits
    do{
        // User input for menu
        cout<<"\n\n----------MENU----------";
        cout<<"\n1). Enter a new job";
        cout<<"\n2). List all current jobs";
        cout<<"\n3). Exit";
        cout<<"\nEnter menu choice: ";
        cin>>input;

        if (input < 1 || input > 3)
        {
            cout<<"\nWrong input, try again!";
        }
        // Switch statements for each menu selection and for catching errors
        switch(input)
        {
            case 1: 
                break;
            case 2:
                break;
            case 3:
                cout<<"Thank you!";
                break;
        }
    }
    while (input != 3); 
}

/** FUNCTION
 * Prints all element in a 2D array
 * @param  {int*} a, {int} len
 */
void printMatrix(int *a, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(i % 4 == 0 && i != 0)
        {
            cout<<"\n";
        }
        cout<<*(a + i)<<"\t";
    }
}

/** FUNCTION
 * Finds desired integer in a 2D array
 * @param  {int*} a, {int} len
 */
void findInteger(int *a, int len)
{
    int find = 0;
    cout<<"Enter an integer to locate: ";
    cin>>find;

    for(int i = 0; i < len; i++)
    {
        if (*(a+i) == find)
        {
            cout<<"\n"<<find<<" is located on row "<<(i/4)+1<< " and column "<<(i%4)+1<<".";
        }
    }
}

/** FUNCTION
 * Swaps columns 1 and 3 in a 2D array
 * @param  {int*} a, {int} len
 */
void swapCol(int *a, int len)
{
    // Temp stores 3rd column values from the 2D array
    for(int i = 0; i <= len; i ++)
    {
        if(i % 4 == 0 && i != 0)
        {
            int temp = *(a+i-4); //Temp stores first column value in the row
            *(a+i-4) = *(a+i-2); //Sets first column [*(a+i-4)] to 3rd column [*(a+i-2)]
            *(a+i-2) = temp; //Sets 3rd column to temp (first column)
        }
    }
    cout<<"Got it!  Column 1 and Column 3 have been swapped.";
}