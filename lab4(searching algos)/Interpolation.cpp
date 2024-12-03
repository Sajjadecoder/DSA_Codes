#include<iostream>
#include<string>
using namespace std;
int InterpolationSearch(int *arr,int n,int k){
    int start = 0;
    int end = n-1;
    while (k>=arr[start] && k<=arr[end] && start<=end)
    {
        int mid = start + ((k-arr[start])*(end-start)/(arr[end]-arr[start]));
        if (arr[mid]==k)
        {
            return mid;
        }if (arr[mid]<k)
        {
            start = mid + 1;
        }else{
            end = mid -1;
        }
        
        
    }
    return -1;
    
}

int main(){
    int n,k;
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter target element: ";
    cin>>k;
    int retVal = InterpolationSearch(arr,n,k);
    if (retVal==-1)
    {
        cout<<retVal;
    }else{
        cout<<k<< " found at index: "<<retVal;
    }
    
    
    return 0;
}