#include<iostream>
#include<string>
using namespace std;

void insertionSort(int *arr,int n){
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j;
        for ( j = i-1; j>=0; j--)
        {
            if (temp<arr[j])
            {
                arr [j+1] = arr[j];
            }else{
                break;
            }
            
        }
        arr[j+1] = temp;
        
    }
    
}
void insSort(int *arr,int n){
    for (int i = 1; i <n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        
    }
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int arr2[n];
    cout<<"Elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>arr2[i];
    }
    insertionSort(arr,n);//for loop
    insSort(arr2,n);//while loop
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr2[i]<<" ";
    }
    return 0;
}