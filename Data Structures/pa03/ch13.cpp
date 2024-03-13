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

int main()
{
    // Initialize array and determine it's number of rows and columns
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};
    int input = 0;
    int *point;
    point = array;
    int l = sizeof array / sizeof *point;

    // Excecute menu until user exits
    do{
        // User input for menu
        cout<<"\n\n----------MENU----------";
        cout<<"\n1). Display matrix";
        cout<<"\n2). Find integer";
        cout<<"\n3). Swap column 1 and 3";
        cout<<"\n4). Exit";
        cout<<"\nEnter your value: ";
        cin>>input;

        if (input < 1 || input > 4)
        {
            cout<<"\nWrong input, try again!";
        }
        // Switch statements for each menu selection and for catching errors
        switch(input)
        {
            case 1: 
                printMatrix(point, l);
                break;
            case 2:
                findInteger(point, l);
                break;
            case 3:
                swapCol(point, l);
                break;
            case 4:
                cout<<"Thank you!";
        }
    }
    while (input != 4); 
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