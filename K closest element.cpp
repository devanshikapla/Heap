// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector < int > ans;
        priority_queue < pair < int , int >> pq;
        for(int i = 0 ; i < n ; i++){
            if(x - arr[i] != 0) pq.push({-1* abs(arr[i] - x) , arr[i]});
           
        }
        for(int i = 0 ; i < k ; i++){
            //ans.insert(ans.begin(), pq.top().second);
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
