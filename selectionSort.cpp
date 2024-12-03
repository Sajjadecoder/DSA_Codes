#include <iostream>
#include <string>
using namespace std;
int main()
{
    int index;
    /*for (int i = 0; i < 5; i++)
    {
        index = i;
        int min = arr[i];                   //O(n^2) complexity
        for (int j = i+1; j < 5; j++)
        {
            if (arr[j]<min)
            {
                min = arr[j];
                index = j;
            }

        }
        swap(arr[i],arr[index]);

    }
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }*/
        int i = 0;
        int j = i + 1;          //O(n) complexity
        int n = 5;
        int change = 0;
        int minIndex = i;
        int arr[5] = {22, 14, 35, 65, 1};
        while (i < n - 1)
        {
            if (change == 1)
            {
                minIndex = i;
            }

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
            if (j == n - 1)
            {
                swap(arr[i], arr[minIndex]);
                i++;
                j = i + 1;
                change = 1;
            }
            else
            {
                j++;
                change = 0;
            }
        }
        for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}