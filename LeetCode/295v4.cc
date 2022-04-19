class MedianFinder {
    multiset<int> s;
    multiset<int>::iterator med;
public:
    MedianFinder(): med{s.begin()} {
    }
    
    void addNum(int num) {
        auto size = s.size();
        s.emplace(num);
        if(size & 1) {
            if(num >= *med) med = next(med);
        }
        else {
            if(size == 0) med = s.begin();
            else if(num < *med) med = prev(med);
        }
    }
    
    double findMedian() {
        auto size = s.size();
        if(size & 1) return *med;
        return 0.5*(*prev(med)+*med);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */