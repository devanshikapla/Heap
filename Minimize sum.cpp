class Solution {
public:
    int minimizeSum(int n, vector<int> arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0; i < n ; i++){
            pq.push(arr[i]);
        }
        int cost = 0;
        while(pq.size() > 1){
            int top  = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            int newSum = top + top2;
            cost = cost + newSum;
            pq.push(newSum);
        }
        return cost;
    }
};
