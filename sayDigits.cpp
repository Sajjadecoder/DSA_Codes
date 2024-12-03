#include <iostream>
#include <string>
#include <vector>
using namespace std;

void say(string *a, int num, vector<int> &digits)
{
    if (num <= 0)
    {
        return;
    }
    int digit = num %10;
    num/=10;
    //digits.push_back(digit);
    say(a,num,digits);
    cout<<a[digit]<<" ";
}
int main()
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int num;
    vector<int> digits;
    cin >> num;
    say( arr,num, digits);
    // for (int i = digits.size()-1; i >= 0; i--)
    // {
    //     cout<<arr[digits[i]]<<" ";
    // }
    
    return 0;
}