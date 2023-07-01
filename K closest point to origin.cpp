class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector < vector < int >> ans;
        int n = points.size();
        priority_queue < pair < int , vector < int > >> pq;
        for(int i = 0 ; i < n ; i++){
            pq.push({points[i][0] * points[i][0] + points[i][1]*points[i][1] ,{points[i][0], points[i][1]} });
            if(pq.size() > k) pq.pop();
        }
        while(pq.size() > 0){
            ans.push_back({pq.top().second});
            pq.pop();
        }
        return ans;
    }
};
