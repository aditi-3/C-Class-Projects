#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    srand((unsigned) time(NULL));
    int price = 10000 + (rand() % 100000);
    cout<<"\n"<<price;
    string check = to_string(price);
    char temp = check[0];
    int dg = 0;
    int digits[10] = {0};
    string money = "";
    //cout<<"\ncheck.substr(i,i+1): "<<check[1];
    //cout<<"\ntemp: "<<temp;
    //bool wearegoing = false;
    // for(int i = 1; i < check.length(); i++)
    // {
    //     if(check[i] = temp)
    //     {
    //         price = 10000 + (rand() % 100000);
    //         //i = 0;
    //         cout<<"\n"<<price;
    //         check = to_string(price);
    //         temp = check[i-1];
    //         cout<<"\ncheck.substr(i,i+1): "<<check.substr(i,i+1);
    //         cout<<"\ntemp: "<<temp;
    //     }
    // }
            do{
                int num = rand() %  10;
                
                if(digits[num] != 1)
                {
                    money[dg] = to_string(num)[0];
                    dg++;
                }
                
                digits[num] = 1;
    
            }while(dg < 5);
    // cout<<"\ntemp: "<<temp;
    // while(i<0)
    // {
    //     if(check.find(temp) == 0)//string::npos)
    //     {
    //     cout<<"\ncheck.find(temp): "<<check.find(temp);
    //     cout<<"\ntemp: "<<temp;
    //         price = 10000 + (rand() % 100000);
    //         cout<<"\n"<<price;
    //         check = to_string(price);
    //         //i = 0;
    //         temp = check.substr(i,i+1);
    //         i++;
    //     }
    //     else
    //     {
    //         i++;
    //     }
    // }
    //cout<<"\n"<<price;
}
