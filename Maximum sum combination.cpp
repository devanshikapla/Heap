 vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.rbegin(),A.rend());
        sort(B.rbegin(),B.rend());

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> vis;
        vector<int> ans;
        
        //store the max element with index
        pq.push({ A[0]+B[0] , {0, 0} });
        vis.insert({0,0});
        
        while (!pq.empty() && ans.size() < K){
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            ans.push_back(sum);
    
            // Insert the adjacent sum combinations into the queue if they are valid
            if (i+1 < N && vis.count( {i+1, j} ) == 0){
                pq.push({ A[i+1]+B[j] , {i+1, j} });
                vis.insert( {i+1, j} );
            }
            
            if (j+1 < N && vis.count( {i, j+1} ) == 0){
                pq.push({ A[i]+B[j+1] , {i, j+1} });
                vis.insert( {i, j+1} );
            }
        }
    
        return ans;
    }
