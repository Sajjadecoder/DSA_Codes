#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    vector<int> arr1;

    vector<int> arr2;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr1.push_back(num);
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        arr2.push_back(num);
    }
    vector<int> newArray;
    int start1 = 0;
    int start2 = 0;
    int end1 = arr1.size();
    int end2 = arr2.size();

    while (start1 < end1 && start2 < end2)
    {
        // cout<<"hh";
        if (arr1[start1] < arr2[start2])
        {
            newArray.push_back(arr1[start1]);
            start1++;
        }
        else
        {
            newArray.push_back(arr2[start2]);
            start2++;
        }
    }

    while (start1 < end1)
    {
        newArray.push_back(arr1[start1++]);
    }
    while (start2 < end2)
    {
        newArray.push_back(arr2[start2++]);
    }

    for (int i = 0; i < newArray.size(); i++)
    {
        cout << newArray[i] << " ";
    }
    return 0;
}