#include <iostream>
#include <string>
using namespace std;
bool recBinSearch(int *arr, int target, int start, int end)
{
    if (start > end)
    {
        return false;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
        return true;
    }
    else if (arr[mid] < target)
    {

        start = mid + 1;
        return recBinSearch(arr, target, start, end);
    }
    else
    {
        end = mid - 1;
        return recBinSearch(arr, target, start, end);
    }
}

int main()
{
    int arr[6] = {1, 3, 5, 6, 7, 8};
    if (recBinSearch(arr, 0, 0, 5))
    {
        cout << "Found";
    }
    else
    {
        cout << "not found";
    }

    return 0;
}