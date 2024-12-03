#include <iostream>
#include <string>
#include <vector>
using namespace std;

void f(int index, vector<int> &v, int n, int *arr)
{
    if (index >= n)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    v.push_back(arr[index]);
    f(index + 1, v, n, arr);
    v.pop_back();
    f(index + 1, v, n, arr);
}
void sumNumbers(int i,vector<int>&v,int n,int *arr,int K){
    if (i >= n)
    {
        int Sum= 0;
        for (int l = 0; l < v.size(); l++)
        {
            Sum+=v[l];
        }
        // cout<<"Sum: "<<Sum<<endl;
        if (Sum==K)
        {
            for (int l = 0; l < v.size(); l++)
            {
                cout<<v[l]<<" ";
            }
            cout<<endl;
        }
        
        return;
    }
    v.push_back(arr[i]);
    sumNumbers(i+ 1, v, n, arr,K);
    v.pop_back();
    sumNumbers(i + 1, v, n, arr,K);

}
int main()
{
    int array[] = {3, 1, 2,4,6,7,8,5};
    vector<int> v;
    f(0,v,8,array);
    // vector<int> v2;
    // int  arr2[5] = {1,2,3,2,5};
    // sumNumbers(0,v2,5,arr2,6);

    return 0;
}