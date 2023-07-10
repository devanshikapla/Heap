class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector < array < int , 3 >> sorted;
        for(int i = 0 ; i < n ; i++){
            int start = tasks[i][0];
            int process = tasks[i][1];
            sorted.push_back({start, process , i});
        }
        sort(sorted.begin() , sorted.end());
        vector < int > result;
        long long cur = 0;
        long long index = 0;
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<> > pq;
        while(index < n || !pq.empty()){
            if(pq.empty() && cur < sorted[index][0]){
                cur = sorted[index][0];
            }
            while(index < n && sorted[index][0] <= cur){
                pq.push({sorted[index][1] , sorted[index][2]});
                index++;
            }
            pair < int , int > curTask = pq.top();
            pq.pop();
            cur += curTask.first;
            result.push_back(curTask.second);
        }
        return result;
    }
};
