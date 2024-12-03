/*Create a program that allows the user:
o To insert an element at a specific position in an array.
o To delete an element from a given position in the array.*/

#include <iostream>
#include <string>
using namespace std;

void insertElement(int *&arr, int &size, int element, int pos)
{
    
    int *temp = new int[size + 1];
    for (int i = 0; i < pos; i++)
    {
        temp[i] = arr[i];
    }
    temp[pos] = element;
    for (int i = pos; i < size; i++)
    {
        temp[i+1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size++;
    return;
}void deleteElement(int *&arr, int &size, int pos)
{
    int *temp = new int [size-1];
    int count = 0;

    for (int i = 0; i <pos; i++)
    {
        temp[i] = arr[i];
            
    }
    for (int i = pos; i < size-1; i++)
    {
        temp[i] = arr[i+1];
        
    }
    delete[]arr;
    arr = temp;
    size--;
    
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Insert position of insertion: ";
    int pos, elem;
    cin >> pos;
    cout << "Enter number to be inserted: ";
    cin >> elem;
    insertElement(arr, n, elem, pos);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    deleteElement(arr, n, 3);
    cout<<endl;
    for (int i = 0; i <n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}