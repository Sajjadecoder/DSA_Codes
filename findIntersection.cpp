#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){

    vector <int> array1;
    vector <int> array2;
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        array1.push_back(num);
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        array2.push_back(num);
    }
    vector <int> arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (array1[i]==array2[j])
            {
                if (arr.size()==0)
                {
                    arr.push_back(array2[j]);
                }else{
                    if (array1[i]>arr[arr.size()-1])
                    {
                        arr.push_back(array1[i]);
                    }
                    
                }
                
            }
            
        }
        
    }
    for (int i = 0; i < array1.size(); i++)
    {
        cout<<array1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < array2.size(); i++)
    {
        cout<<array2[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    



    return 0;
}