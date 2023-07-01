class Solution{
    public:
    long long kthsmallest(long long arr[] , long long k , long long n){
        priority_queue<long long> q;
        for(long long i = 0 ; i < n ; i++){
            q.push(arr[i]);
            if(q.size() > k ){
                q.pop();
            }
        }
        return q.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long sum = 0;
        int first = kthsmallest(A , K1 , N );
        int second = kthsmallest( A , K2 , N);
        for(long long i = 0; i < N ; i++){
            if(A[i] > first && A[i] < second){
                sum = sum + A[i];
            }
        }
        return sum;
    }
};
