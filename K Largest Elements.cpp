vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    //heap based solution
	    //Declaration of priority queue
	    priority_queue<int,vector<int>,greater<int>>pq; //min heap 
	    for(int i = 0 ; i < n ; i++){
	        pq.push(arr[i]);
	        if(pq.size() > k){
	            pq.pop();
	        }
	    }
	    vector < int > ans;
	    while(!pq.empty()){
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    sort(ans.rbegin() , ans.rend());
	    return ans;
	}
