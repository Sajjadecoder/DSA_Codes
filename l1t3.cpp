/*Declare an integer array arr with 5 elements and initialize it with values 10, 20, 30, 40, and
50. Declare a pointer arrPtr and assign the address of the first element of the array to it. Use
pointer arithmetic to print the values of all elements in the array using the pointer Increment
the pointer to point to the next element and print the updated value. Repeat this process for
each element in the array. Modify the values in the array through the pointer by doubling
each element. Print the modified array using both array notation and pointer notation.*/
#include<iostream>
#include<string>
using namespace std;

int main(){
    int array[5] = {10,20,30,40,50};
    int *ptr = array;
    for (int i = 0; i < 5; i++)
    {
        cout<<*ptr<<" ";
        ptr++;
    }
    ptr = array;
    cout<<endl;
    for (int i = 0; i < 5; i++)
    {
        *(ptr+i) *=2;

    }
    for (int i = 0; i < 5; i++)
    {
        cout<<*ptr<<" ";
        ptr++;
    }
    
    return 0;
}