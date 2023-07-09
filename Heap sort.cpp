#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void heapify(int arr[] , int n , int i){
    //inititalize largest as root;
    int largest = i;
    //left
    int left = 2 * i + 1;
    //right;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr , n , largest);
    }
}

void heapsort(int arr[] , int n ) {
    //build max heap using heapify method;
    for(int i = n /2 - 1; i >= 0 ; i--){
        heapify(arr , n , i);
        
    }
    for(int i = n - 1; i >= 0 ; i--){
        swap(arr[0] , arr[i]);
        //rearranging the heap again in order of max heap
        heapify(arr , i , 0);
    }
}

void printArray(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);

    cout<<"original array is" <<endl;
    printArray(arr , N);
    cout<<endl;
    heapsort(arr, N);
    cout<<"sorted array is" <<endl;
    printArray(arr, N);
    return 0;
}
