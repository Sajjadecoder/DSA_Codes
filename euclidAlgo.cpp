#include<iostream>
#include<string>
using namespace std;
void gcd(int n1,int n2,int &ans){
    //a = bq+r
    if (n2==0)
    {
        return;
    }
    
    int a = min(n1,n2);
    int b = max(n1,n2);
    // a = a*(b / a) + (b%a);
    ans = a;
    gcd(a,b%a,ans); 
}

int main(){
    int n1,n2,ans = 0;
    cin>>n1>>n2;
    gcd(n1,n2,ans);
    cout<<"Ans: "<<ans;
    return 0;
}