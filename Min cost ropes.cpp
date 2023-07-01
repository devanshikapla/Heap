long long minCost(long long arr[], long long n) 
    {
        // Your code here Aditya
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        
        //step-1
        for(long long i=0;i<n;i++)
        pq.push(arr[i]);
        
        //step2
        long long sum_total=0;
        while(pq.size()>1)
        {
            long long sum=0;
            long long x=pq.top();
            pq.pop();
            sum_total+=pq.top()+x;
            sum=pq.top()+x;
            pq.pop();
            pq.push(sum);
        }
        return sum_total;
        
    }
