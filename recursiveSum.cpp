#include <iostream>
#include <string>
using namespace std;
int fun(int *arr, int sum, int size, int i)
{
    if (i == size)
    {
        return sum;
    }
    else
    {
        sum += arr[i];
        i++;
        return fun(arr, sum, size, i);
    }
}

int main()
{
    int arr[5] = {1, 2, 4, 6, 6};
    int Sum = fun(arr, 0, 5, 0);
    cout << "Sum: " << Sum;
    return 0;
}