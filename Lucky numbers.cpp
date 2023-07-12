class Solution{
    public:
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        // Your code goes here 
        vector < int > ans;
        priority_queue< pair<int, int> > pq;
        for(int i = 0 ; i < n ; i++){
            int diff = abs(arr[i] - x);
            pq.push({diff , arr[i]});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;
    }  
};
