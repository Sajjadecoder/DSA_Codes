#include <iostream>
#include <string>
using namespace std;

int** addition(int **arr3,int **arr1, int **arr2, int n1, int n2)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <2; j++)
        {
            *(*(arr3+i)+j) = *(*(arr2+i)+j)+*(*(arr1+i)+j);
        }
        
    }
    return arr3;
        

}
int** subtraction(int **arr3,int **arr1, int **arr2, int n1, int n2)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <2; j++)
        {
            *(*(arr3+i)+j) = *(*(arr2+i)+j)-*(*(arr1+i)+j);
        }
        
    }
    return arr3;
        

}
int main()
{
    int **arr1 = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        *(arr1+i) = new int [2];

    }
    int **arr2 = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        *(arr2+i) = new int [2];

    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<"arr1 element: ";
            cin>>arr1[i][j];
            cout<<"arr2 element: ";
            cin>>arr2[i][j];
        }
        
    }
    int **arr3 = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        *(arr3+i) = new int [2];

    }
    cout<<"After addition: \n";
    arr3 = addition(arr3,arr1,arr2,2,2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <2; j++)
        {
            cout<<*(*(arr3+i)+j)<<" ";
        }
        cout<<endl;
    }cout<<"After subtraction: \n";
    arr3 = subtraction(arr3,arr1,arr2,2,2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <2; j++)
        {
            cout<<*(*(arr3+i)+j)<<" ";
        }
        cout<<endl;
    }
    
}