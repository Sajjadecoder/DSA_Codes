#include<iostream>
#include<string>
using namespace std;
void heapify(int *arr,int i,int n){
    int largest = i;
    int left = (2*i)+1;
    int right= (2*i)+2;
    if (left<n && arr[left]>arr[largest])
    {
        largest = left;
    }
    if (right<n && arr[right]>arr[largest])
    {
        largest = right;
    }
    if (largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
    
    
}
void buildMaxHeap(int *arr,int n){
    for (int i = (n/2)-1; i >=0; i--)
    {
        heapify(arr,i,n);   
    }
    
}
void print(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
}
void heapSort(int *arr,int n){
    //step1: Convert the array into maxHeap
    buildMaxHeap(arr,n);
    //step 2: pehle first element ko last element se swap kro then apply heapify on first element
    for (int i = (n-1); i > 0; i--)
    {
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
    
}


int main(){
    int arr[] = {10,3,8,9,5,13,18,14,11,70};
    // buildMaxHeap(arr,10);

    print(arr,10);
    heapSort(arr,10);
    print(arr,10);
    
    return 0;
}