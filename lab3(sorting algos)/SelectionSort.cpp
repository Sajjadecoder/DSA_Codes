#include<iostream>
#include<string>
using namespace std;
int main(){
    double arr[10];
    for (int i = 0; i < 10; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < 9; i++)
    {
        int minIndex = i;
        for (int j = i; j < 10; j++)
        {
            if (arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
            
        }
        swap(arr[i],arr[minIndex]);
        
    }
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
    return 0;
}