class MedianFinder {
public:
    //max heap
    priority_queue < int > pq;
    //min heap
    priority_queue < int , vector < int > , greater < int >> pq1;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq.empty() || num < pq.top()){
            pq.push(num);
            
        }
        else{
            pq1.push(num);
        }
        if(abs((int)pq.size() - (int)pq1.size()) > 1){
            int k = pq.top();
            pq1.push(k);
            pq.pop();
        }
        else if(pq.size() < pq1.size()){
            int p = pq1.top();
            pq.push(p);
            pq1.pop();
        }
    }
    
    double findMedian() {
        if(pq.size() == pq1.size()){
            double median = (pq.top() + pq1.top()) / 2.0;
            return median;
        }
        //if odd number of elements then ans lies in top of left max heap;
        return (double)pq.top();
    }
};
