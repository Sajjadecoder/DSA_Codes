#include<iostream>
#include<string>
using namespace std;
int findIndex(int *arr,int size,int t,int i){
    if (i==size)
    {
        return -1;
    }else{
        if (arr[i] == t)
        {
            return i;
        }else{
            i++;
            return findIndex(arr,size,t,i);
        }
        
    }
    
}

int main(){
    int arr[5] = {1,3,5,6,7};
    int index = findIndex(arr,5,5,0);
    if (index == -1)
    {
        cout<<"Not found";
    }else{
        cout<<"Index: "<<index;
    }
    
    return 0;
}