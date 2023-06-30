 vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map < int , int > mpp;
        priority_queue < pair < int , int >> pq;
        vector < int > ans;
        for(auto it : nums){
            mpp[it]++;
        }
        for(auto it : mpp){
            pq.push({it.second , it.first});
        }
        for(int i = 0 ; i < k ; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
