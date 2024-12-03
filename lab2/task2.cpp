/*Create a simple container class called IntArray that dynamically manages an array of integers.
Implement the Rule of Three (copy constructor, copy assignment operator, and destructor) to
properly manage memory.*/
#include<iostream>
#include<string>
using namespace std;
class IntArray{
    int *arr;
    int n;
    public:
    IntArray(){}
    IntArray(int *a,int n):n(n) {
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = a[i];
        }
        
    }
    int getN(){return n;}
    IntArray(IntArray &obj){
        n = obj.getN();
        arr = new int[obj.getN()];
        for (int i = 0; i < obj.getN(); i++)
        {
            arr[i] = obj.arr[i];
        }
        
    }
    IntArray& operator =(IntArray &obj){
        *this = obj;
        return *this;
    }
    void disp(){
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
        
    }
    ~IntArray(){delete [] arr;}
};
int main(){
    int arr[5] = {1,2,3,4,5};
    int arr2[5] = {6,7,8,9,10};
    IntArray obj1(arr,5);
    IntArray obj2(arr2,5);
    obj1.disp();
    obj2.disp();
    IntArray obj3(obj2);
    obj3.disp();
    obj2.disp();
    return 0;
}