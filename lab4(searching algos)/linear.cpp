#include<iostream>
#include<string>
using namespace std;
int linearSearch(int *a,int n,int t){
    for (int i = 0; i < n; i++)
    {
        if (a[i]==t)
        {
            return i;
        }
        
    }
    return -1;
    
}

int main(){
    int a[] = {11,12,145,46,34,57,79,75};
    int pos = linearSearch(a,8,34);
    if (pos==-1)
    {
        cout<<"Not found";

    }else{
        cout<<"Found at index: "<<pos;
    }
    
    return 0;
}