/*Write a C++ program that uses a jagged array to represent employee information for three
different companies. Each company has a varying number of employees, and each employee has
a name and salary. The program should allow users to input employee information, display it,
and find the average salary for each company.*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    int *arr[3];
    int empCount[3];
    for (int i = 0; i <3; i++)
    {
        cout<<"Enter employee count for company "<<i+1<<": ";
        cin>>empCount[i];
        arr[i] = new int [empCount[i]];
        for (int j = 0; j < empCount[i]; j++)
        {
            cout<<"Enter salary for Emp "<<j+1<<": ";
            cin>>arr[i][j];

        }
    }
    for (int i = 0; i <3; i++)
    {
        double avg = 0.0;
        int sum = 0;
        for (int j = 0; j < empCount[i]; j++)
        {
            sum+=arr[i][j];
        }
        avg = double(sum)/double(empCount[i]);
        cout<<"Average of Company "<<i+1<<": "<<avg<<endl;
        
    }
    for (int i = 0; i <3; i++)
    {
        cout<<"Company "<<i+1<<" salaries:\n";
        for (int j = 0; j < empCount[i]; j++)
        {
            cout<<j+1<<". "<< arr[i][j]<<endl;
        }cout<<endl;
        
    }
    
    
    
    return 0;
}