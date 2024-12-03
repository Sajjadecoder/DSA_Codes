/*Create a program that initializes two 3x3 matrices (matrixA and matrixB) with integer values.
You can either initialize them manually or use user input. Implement a function to print the
original matrices (matrixA and matrixB). Implement a function transposeMatrix that takes a
matrix as input and returns its transpose. Print the original matrices and their transposes.
Implement a function sumMatrices that takes two matrices as input and returns the matrix
resulting from their sum. Print the original matrices and the result of their sum. Allow the
user to input the values for the matrices. Modify the program to initialize matrices based on
user input. Implement error handling to ensure that the user provides valid dimensions and
values for the matrices. Display appropriate error messages if the dimensions or values are
invalid.*/
#include <iostream>
#include <string>
using namespace std;

void initialize(int (*arr)[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> *(*(arr + i) + j);
        }
    }
}
void transpose(int (*arr)[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            int temp = *(*(arr + i) + j);
            *(*(arr + i) + j) = *(*(arr + j) + i);
            *(*(arr + j) + i) = temp;
        }
    }
}
void print(int (*arr)[3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int arr1[3][3];
    int arr2[3][3];
    cout << "Initialize Array 1:\n";
    initialize(arr1);
    cout << "Initialize Array 2:\n";
    initialize(arr2);
    cout << "Original Array 1:\n";
    print(arr1);
    cout << "Original Array 2:\n";
    print(arr2);
    transpose(arr1);
    transpose(arr2);
    cout << "Transpose Array 1:\n";
    print(arr1);
    cout << "Transpose Array 2:\n";
    print(arr2);
    return 0;
}