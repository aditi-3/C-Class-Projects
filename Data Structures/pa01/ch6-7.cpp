/**
 * @name Aditi Verma
 *       ASSIGNMENT 1 - Ingeters
 * @date 2/22/24
 */

#include <iostream>
#include <stdio.h>
using namespace std;

/** FUNCTION
 * Prints all element in a 2D array
 * @param  {int [][4]} a, {int} r, {int} c 
 */
void printMatrix(int a[][4], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int x = 0; x < c; x++)
        {
            cout<<a[i][x]<<"\t";
        }
        cout<<"\n";
    }
}

/** FUNCTION
 * Finds desired integer in a 2D array
 * @param  {int [][4]} a, {int} r, {int} c 
 */
void findInteger(int a[][4], int r, int c)
{
    int find = 0;
    cout<<"Enter an integer to locate: ";
    cin>>find;

    for(int i = 0; i < r; i++)
    {
        for(int x = 0; x < c; x++)
        {
            if (a[i][x] == find)
            {
                cout<<"\n"<<find<<" is located on row "<<i+1<< " and column "<<x+1<<".";
            }
        }
    }
}

/** FUNCTION
 * Swaps columns 1 and 3 in a 2D array
 * @param  {int [][4]} a, {int} r
 */
void swapCol(int a[][4], int r)
{
    // Temp stores 3rd column values from the 2D array
    int temp[4];
    for(int i = 0; i < r; i ++)
    {
        temp[i] = a[i][2];
    }
    
    // Sets column 3 to column 1
    for(int i = 0; i < r; i ++)
    {
        a[i][2] = a[i][0];
    }

    // Sets column 1 to column 3 using temp
    for(int i = 0; i < r; i ++)
    {
        a[i][0] = temp[i];
    }
    cout<<"Got it!  Column 1 and Column 3 have been swapped.";
}

int main()
{
    // Initialize array and determine it's number of rows and columns
    int array[][4] = {{1, 3, 5, 7}, {9, 11, 13, 15}, {17, 19, 21, 23}, {25, 27, 29, 31}};
    int row = sizeof array / sizeof (array[0]);
    int column = sizeof array[0] / sizeof(int);
    int input = 0;

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
                printMatrix(array, row, column);
                break;
            case 2:
                findInteger(array, row, column);
                break;
            case 3:
                swapCol(array, row);
                break;
            case 4:
                cout<<"Thank you!";
        }
    }
    while (input != 4); 
}