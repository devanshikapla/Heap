#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int A[n];
    unordered_map < int , int > mpp;
    vector < int > ans;
    priority_queue <pair < int , int >> pq;
    
    for(int i = 0 ; i < n ; i++){
        cin>>A[i];
    }
    //pushing elements into map to count the frequency;
    for(int i = 0 ; i < n ; i++){
        mpp[A[i]]++;
    }
    //creating iterator to iterate over map pushing elements into maxheap in the form
    //{frequency , element}
    for(int i = 0 ; i < n ; i++){
        pq.push({-1*mpp[A[i]],A[i]});
    }
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
   
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	    
	}
	return 0;
}
