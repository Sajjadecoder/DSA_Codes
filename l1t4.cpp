/*Declare two integer variables, num1 and num2, and initialize them with values of your choice.
Declare two integer pointers, ptr1 and ptr2. Assign the addresses of num1 and num2 to ptr1
and ptr2, respectively. Implement a function swapUsingPointers that takes two integer
pointers as parameters and swaps the values they point to. Call the swapUsingPointers
function with ptr1 and ptr2 as arguments to swap the values of num1 and num2. Print the
values of num1 and num2 after the swap to verify that the values have been successfully
swapped.*/

#include <iostream>
#include <string>

using namespace std;
void swapUsingPointers(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp; 
}
int main()
{
    int n1 = 5;
    int n2 = 10;
    int *p1 = &n1;
    int *p2 = &n2;
    swapUsingPointers(p1, p2);
    cout << "Num1: " << n1 << "\nNum2: " << n2;

    return 0;
}