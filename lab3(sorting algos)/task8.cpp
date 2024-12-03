#include <iostream>
#include <string>
using namespace std;
int main()
{
    int array[] = {34, 34, 34, 56, 56, 65, 88, 88, 88, 92, 92, 1, 1, 88, 54};
    int n = sizeof(array) / 4;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = array[i];
        while (j >= 0 && temp < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl
         << endl;

    int number = array[0];
    int maxCount = 0;
    int maxIndex = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (array[j] == number)
        {
            count++;
            j++;
        }
        else
        {
            i = j;
            number = array[j];
            if (count > maxCount)
            {

                maxCount = count;
                maxIndex = j - 1;
            }
            count = 0;
        }
    }

    cout << array[maxIndex];

    return 0;
}