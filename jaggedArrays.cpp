#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"Enter rows: ";
    cin>>n;
    int *arr[n];
    int col[n];
    for (int i = 0; i < n; i++)
    {
        int cols;
        cout<<"Enter cols: ";
        cin>>cols;
        col[i] = cols;
        arr[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            cout<<"Enter elements: ";
            cin>>arr[i][j];
        }
      
        
    }

    for (int i = 0; i < n; i++)
    {
        // cout<< sizeof(arr[i])/sizeof(arr[i][j])<<endl;
        for (int j= 0; j <col[i]; j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<endl;
        
    }
    for (int i = 0; i < n; i++)
    {
        delete [] arr[i];
    }
    
    
    
    return 0;
}