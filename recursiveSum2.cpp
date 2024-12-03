#include<iostream>
#include<string>
using namespace std;
int Sum(int &num,int &sum){
    if (num==0)
    {
        return sum;
    }
    int digit = num%10;
    num/=10;
    sum+=digit;
    return Sum(num,sum);
}

int main(){
    int n;
    int sum = 0;
    cin>>n;
    Sum(n,sum);
    cout<<"Ans: "<<sum;
    return 0;
}