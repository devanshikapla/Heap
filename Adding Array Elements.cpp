int minOperations(int arr[], int n, int k) {
        // code here
          priority_queue<int,vector<int>,greater<int>>pq;
          for(int i = 0 ; i < n ; i++){
              pq.push(arr[i]);
          }
          int cnt = 0; //variable to count operations
          while(pq.top() < k){
              if(pq.empty()) return -1;
              int temp = pq.top();
              pq.pop();
              if(pq.empty()) return -1;
              
              int temp2 = pq.top();
              pq.pop();
              int sum = temp + temp2;
              pq.push(sum);
              cnt++;
          }
          return cnt;
    }
