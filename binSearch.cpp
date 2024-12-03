#include<iostream>
#include<string>
using namespace std;
int binarySearch(int arr[],int n){
    int key;
    cout<<"Key: ";cin>>key;
    int i=0;
    int j=n-1;
    while (i<=j)
    {
        int mid = i+((i-j)/2);//2^31-1 ki condition k liye
        if (arr[mid]==key)
        {
            return mid;
        }else if(arr[mid]<key){
            i = mid+1;
        }else{
            j=mid-1;
        }
        
    }
    return -1;
    
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    int retVal = binarySearch(arr,n);
    if (retVal==-1)
    {
        cout<<"Not found";
    }else{
        cout<<"Found at position "<<retVal;
    }
    
 
    return 0;
}