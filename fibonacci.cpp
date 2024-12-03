#include<iostream>
#include<string>
using namespace std;
void fibonacci(int prev,int curr,int count,int n){
    if (count == n)
    {
        cout<<"\nSeries ended\n";
        return;
    }
    //int temp = curr;
    curr+= prev;
    prev = curr - prev;
    cout<<curr<<" ";
    count++;
    fibonacci(prev,curr,count,n);   
}

int main(){
    int n;
    cin>>n;
    cout<< "0 1 ";
    fibonacci(0,1,0,n-2);
    return 0;
}