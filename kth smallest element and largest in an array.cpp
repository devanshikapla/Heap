#include <bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	
	//declaration of max heap

	priority_queue < int > pq;
	//min heap
	priority_queue<int, vector<int>, greater<int>> pq1;
	int ans = -1;
	for(int i = 0 ; i < n ; i++){
		pq.push(arr[i]);
		if(pq.size() > k) pq.pop();

	}
	ans = pq.top();
	int res = -1;
	for(int i = 0 ; i < n ; i++){
		pq1.push(arr[i]);
		if(pq1.size() > k) pq1.pop();
	}
	res = pq1.top();
	return {ans , res};

}
