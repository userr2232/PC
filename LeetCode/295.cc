class MedianFinder {
    int n;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder(): n{0} {
        
    }
    
    void addNum(int num) {
        if(n == 0) max_heap.push(num);
        else{
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
            if(max_heap.size() < min_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        n++;
    }
    
    double findMedian() {
        return n%2 ? max_heap.top() : 0.5*(max_heap.top()+min_heap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */