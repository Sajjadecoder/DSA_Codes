#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int fun(int num,int p){
    if(p==0){
        return 1;
    }
    else{
        cout<<num<<" "<<p<<endl;;
        // cout<<num<<endl;;
        p/=2;
        return fun(pow(num,p),p);
    }
}
int main(){
    int num = 2;
    int val = fun(2,6);
    // cout<<val;
    return 0;
}