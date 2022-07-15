class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        //cout << minHeap.size() << "\n";
        if(maxHeap.empty())
            maxHeap.push(num);
        else if(!maxHeap.empty() && maxHeap.top() >= num) maxHeap.push(num);
        else minHeap.push(num);
        
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        //if(maxHeap.size() == 0) return 0.0;
        //cout << maxHeap.top() << " " << minHeap.top() << "\n";
        double ans;
        if(maxHeap.size() > minHeap.size()) ans = maxHeap.top();
        else if(minHeap.size() > maxHeap.size()) ans = minHeap.top();
        else{
            ans = ((double)(maxHeap.top())+(double)(minHeap.top()))/2.0;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
