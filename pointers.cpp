#include<iostream>
#include<string>
using namespace std;

void update(int &x){
    x++;
}
int Sum(int *arr,int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=i[arr];
    }
    return sum;
    
}
int main(){
    int x = 5;
    int *ptr = &x;
    cout<<"Before "<<*ptr<<endl;
    update(*ptr);
    cout<<"After "<<*ptr<<endl;

    int arr[6] = {10,2,3,4,5,6};
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(&arr)<<endl;
    cout<<sizeof(*arr)<<endl;
    cout<<arr<<endl;
    cout<<&arr<<endl;
    cout<<*arr<<endl;
    // cout<<"Sum of entire array: "<<Sum(arr,6);
    // cout<<endl<<"Sum of partial array: "<<Sum(arr+3,3);
    int *p = arr;

    cout<<p<<endl;    
    cout<<sizeof(p)<<endl;    
    cout<<*p<<endl;    
    cout<<arr<<endl;    
    
    
    
}