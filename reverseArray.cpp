#include<iostream>
#include<string>
using namespace std;
void rev(int *arr,int i,int j){
    if (i>j)    
    {
        return;
    }
    swap(arr[i],arr[j]);
    rev(arr,i+1,j-1);
    
}
bool checkPalindrome(string s,int i,int j){
    if (i>j)
    {
        return true;
    }
    return s[i] == s[j] && checkPalindrome(s,i+1,j-1);
    
}
int main(){
    int arr[5] = {1,2,3,4,5};
    rev(arr,0,4);
    for (int k = 0; k < 5; k++)
    {
        cout<<arr[k]<<" "; 
    }cout<<endl;
    string s = "niggin";
    if (checkPalindrome(s,0,s.length()-1))
    {
        cout<<"Palindrome\n";
    }else{
        cout<<"not palindrome";
    }
    
    return 0;
}