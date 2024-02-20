#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

class Employee
{
    private:
        int employeeID;
        string name;
        string ssn;
        double wage;
        string department;
        string hireDate;

    public:
        Employee()
        {
            
        }
        Employee(int eID, string n, string s, double w, string d, string date)
        {
            employeeID = eID;
            name = n;
            ssn = s;
            wage = w;
            department = d;
            hireDate = date;
        }
        
        //Setters
        void setEmployeeID(int x)
        {
            employeeID = x;
        }

        void setName(string x)
        {
            name = x;
        }

        void setSSN(string x)
        {
            ssn = x;
        }

        double setWage(int x)
        {
            wage = x;
        }

        void setDepartment(string x)
        {
            department = x;
        }

        void setHireDate(string x)
        {
            hireDate = x;
        }        
        
        //Getters
        int getEmployeeID()
        {
            return employeeID;
        }

        string getName()
        {
            return name;
        }

        string getSSN()
        {
            return ssn;
        }

        double getWage()
        {
            return wage;
        }

        string getDepartment()
        {
            return department;
        }

        string getHireDate()
        {
            return hireDate;
        }
};

int main()
{
    array<Employee, 100> employeeList;
    string input;
    int employeeID;
    string name;
    string ssn;
    double wage;
    string department;
    string hireDate;

    do
    {
        cout<<"\n\n------------------------------------------------------------";
        cout<<"\n\n"<<'\t'<<'\t'<<"**** Operations ****";
        cout<<"\n"<<'\t'<<'\t'<<"====================";
        cout<<"\n"<<'\t'<<'\t'<<" a) Add new employee";
        cout<<"\n"<<'\t'<<'\t'<<" b) Search existing employee";
        cout<<"\n"<<'\t'<<'\t'<<" c) Display employee list";
        cout<<"\n"<<'\t'<<'\t'<<" d) Edit employee information";
        cout<<"\n"<<'\t'<<'\t'<<" e) Delete existing employee";
        cout<<"\n"<<'\t'<<'\t'<<" f) Save data";
        cout<<"\n"<<'\t'<<'\t'<<" g) Read data";
        cout<<"\n"<<'\t'<<'\t'<<" h) Quit";
        cout<<"\n\n"<<'\t'<<'\t'<<"Enter your choice: ";
        cin>>input;

        if(input == "a")
        {
            cout<<"\nEnter employee ID (1-100): ";
            cin>>employeeID;
            cout<<"\nEnter employee name: ";
            getline(cin >> ws, name);
            cout<<"\nEnter last 4 digits of SSN: ";
            cin>>ssn;
            cout<<"\nEnter wage: ";
            cin>>wage;
            cout<<"\nEnter department: ";
            cin>>department;
            cout<<"\nEnter hire date (mm/dd/yyyy): ";
            cin>>hireDate;
            Employee newEmp = Employee(employeeID, name, ssn, wage, department, hireDate);
            employeeList[employeeID-1] = newEmp;
        }
        else if(input == "b")
        {
            cout<<"\nEnter employee's ID to search: ";
            cin>>employeeID;
            Employee emp = employeeList[employeeID-1];
            cout<<"\nEmployee information:";
            cout<<"\nID: "<<emp.getEmployeeID();
            cout<<"\nName: "<<emp.getName();
            cout<<"\nSSN: "<<emp.getSSN();
            cout<<"\nWage: "<<emp.getWage();
            cout<<"\nDepartment: "<<emp.getDepartment();
            cout<<"\nHire Date: "<<emp.getHireDate();
        }
        else if(input == "c")
        {
            cout<<"\n"<<"ID"<<'\t'<<"Employee Name"<<'\t'<<"SSN"<<'\t'<<"Wage"<<'\t'<<"Department"<<'\t'<<"Hire Date";
            cout<<"\n"<<"=="<<'\t'<<"============="<<'\t'<<"==="<<'\t'<<"===="<<'\t'<<"=========="<<'\t'<<"=========";
            for(int i = 0; i < 99; i++)
            {
                Employee temp = employeeList[i];
                if(temp.getName() != "")
                {
                    cout<<"\n"<<temp.getEmployeeID()<<'\t'<<temp.getName()<<'\t'<<temp.getSSN()<<'\t'<<temp.getWage()<<'\t'<<temp.getDepartment()<<'\t'<<'\t'<<temp.getHireDate();
                }
            }
        }
        else if(input == "d")
        {
            cout<<"\nEnter employee's ID to update: ";
            cin>>employeeID;
            Employee emp = employeeList[employeeID-1];
            cout<<"\n\nEmployee information:";
            cout<<"\nID: "<<emp.getEmployeeID();
            cout<<"\nName: "<<emp.getName();
            cout<<"\nSSN: "<<emp.getSSN();
            cout<<"\nWage: "<<emp.getWage();
            cout<<"\nDepartment: "<<emp.getDepartment();
            cout<<"\nHire Date: "<<emp.getHireDate();

            cout<<"\nEnter employee name: ";
            getline(cin >> ws, name);
            cout<<"\nEnter last 4 digits of SSN: ";
            cin>>ssn;
            cout<<"\nEnter wage: ";
            cin>>wage;
            cout<<"\nEnter department: ";
            cin>>department;
            cout<<"\nEnter hire date (mm/dd/yyyy): ";
            cin>>hireDate;
            Employee newEmp = Employee(employeeID, name, ssn, wage, department, hireDate);
            employeeList[employeeID-1] = newEmp;
        }
        else if(input == "e")
        {
            cout<<"Enter employee's ID to delete: ";
            cin>>employeeID;
            employeeList[employeeID-1] = Employee();
        }
        else if(input == "f")
        {
            ofstream file("output.txt"); //create file
            for(int i = 1; i <= employeeList.size(); i++)
            {
                Employee temp = employeeList[i-1];
                if(temp.getName() != "")
                {
                    file<<temp.getEmployeeID()<<" "<<temp.getName()<<" "<<temp.getSSN()<<" "<<temp.getWage()<<" "<<temp.getDepartment()<<" "<<temp.getHireDate()<<"\n";
                }
            }
            cout<<"\nData sucessfully saved.";
        }
        else if(input == "g")
        {
            cout<<"\nEnter the filename: ";
            getline(cin >> ws, input);
            ifstream input_file(input);
            if(input_file.is_open()) //reads each line from the text file
            {
                string line;
                while(getline(input_file, line))
                {
                    string temp = line;
                    employeeID = stoi(temp.substr(0, temp.find(" ")));
                    temp = temp.substr(temp.find(" ")+1);
                    name = temp.substr(0, temp.find(" "));
                    temp = temp.substr(temp.find(" ")+1);
                    name = name + " " + temp.substr(0, temp.find(" "));
                    temp = temp.substr(temp.find(" ")+1);
                    ssn = temp.substr(0, temp.find(" "));
                    temp = temp.substr(temp.find(" ")+1);
                    wage = stod(temp.substr(0, temp.find(" ")));
                    temp = temp.substr(temp.find(" ")+1);
                    department = temp.substr(0, temp.find(" "));;
                    temp = temp.substr(temp.find(" ")+1);
                    hireDate = temp.substr(0);
                    Employee newEmp = Employee(employeeID, name, ssn, wage, department, hireDate);
                    employeeList[employeeID-1] = newEmp;
                }  
                cout<<"\nData sucessfully read.";
                input_file.close();          
            }
        }
    } while (input != "h");
    printf("\nProgrammer: Aditi Verma -- CISC 192 C++ programming");
}