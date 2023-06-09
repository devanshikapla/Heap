#include <bits/stdc++.h> 
void heapify(vector < int > & arr , int n , int i){
	int largest = i;
	int right = (2 * i ) + 1;
	int left = (2 * i ) + 2;
	if(left < n && arr[left] > arr[largest]) largest = left;
	if(right < n && arr[right ] > arr[largest]) largest = right;
	if(i != largest){
		swap(arr[i] , arr[largest]);
		heapify(arr , n , largest);

	}
}
vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	// Write your code here.
	for(int i = arr.size() / 2 - 1 ; i >= 0 ; i--) heapify(arr,n, i);
	return arr;
}
