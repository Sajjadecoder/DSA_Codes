#include<iostream>
#include<string>
using namespace std;
string reverseString(string text,int i,int j){
    if (i>j)
    {
        return text;
    }else{
        swap(text[i],text[j]);
        i++;j--;
        return reverseString(text,i,j);
    }
    
}
int main(){
    string text;
    getline(cin,text);
    int j = text.length()-1;
    string textRev = reverseString(text,0,j);
    cout<<textRev;
    return 0;
}