#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Heap{
    public :
    int arr[100];
    int size;
    
    Heap(){
        arr[0] = -1;
        size = 0;
        
    }
    void insert(int val){
        size = size  + 1;
        int index = size;
        arr[index] = size;
        for(int i = size ; i > 1; i--){
            int parent = i/ 2;
            if(arr[parent] < arr[i]){
                swap(arr[parent] , arr[i]);
                i = parent;
            }
            else{
                return;
            }
        }
    }
    void deleteFromHeap(){
        if(size == 0){
            cout<<"Heap is empty"<<endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        for(int i = 1; i < size; i++){
            int leftIndex = 2 * i;
            int rightIndex = 2* i + 1;
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i] , arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i] , arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
                
            }
        }
    }
    void print(){
        for(int i = 1 ; i < size; i++){
            cout<<arr[i]<<endl;
        }
    }
};

int main(){
    Heap h;
    h.insert(50);
    h.insert(60);
    h.insert(52);
    h.insert(64);
    h.insert(43);
    h.insert(10);
    cout<<"Heap before deletion"<<endl;
    
    h.print();
    h.deleteFromHeap();
    cout<<"Heap after deletion"<<endl;
    h.print();
}
