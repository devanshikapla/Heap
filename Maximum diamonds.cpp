long long maxDiamonds(int a[], int n, int k) {
        // code here
        priority_queue < int > pq;
        for(int i = 0 ; i < n ; i++){
            pq.push(a[i]);
        }
        long long sum = 0;
        while(k > 0){
            long long top = pq.top();
            sum = sum + top;
            pq.pop();
            k--;
            int change = top / 2;
            pq.push(change);
        }
        return sum;
    }
