#include<iostream>
#include<string>
#include<stack>
using namespace std;
void deleteMiddle(stack<int>&arr,int n ){
    if (n&1)
    {
        n/=2;
        
    }else{

        n/=2;
        n--;
    }
    
    int tempArr[n];
    int cnt = 0;
    while (n!=cnt-1)
    {
        tempArr[cnt] = arr.top();
        cout<<"Popped: "<<tempArr[cnt]<<endl;
        arr.pop();
        cnt++;
    }
    for (int i = 0; i <n; i++)
    {
        arr.push(tempArr[i]);
    }
    
    
    
}
int main(){
    stack <int> arr;
    int n;
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        int val;
        cout<<"Enter element: ";
        cin>>val;
        arr.push(val);
    }
    deleteMiddle(arr,n);
    while (!(arr.empty()))
    {
        /* code */
    cout<<arr.top()<<" ";
    arr.pop();    
    }
    
    // cout<<arr.size();    
    
    return 0;
}