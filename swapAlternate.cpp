#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){

    int n;
    cin>>n;
    int array[n];
    for (int i = 0; i < n; i++)
    {

        cin>>array[i];
    }
    if (n&1)
    {
        for (int i = 0; i <n-1; i=i+2)
        {
            swap(array[i],array[i+1]);
        }
        
    }else{
        for (int i = 0; i < n; i=i+2)
        {
            swap(array[i],array[i+1]);
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<< array[i]<<" ";
    }
    

    
    

    return 0;
}