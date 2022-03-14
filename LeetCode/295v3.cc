class MedianFinder {
    int size{0}, left{0}, right{0};
    list<int> l;
    list<int>::iterator median_it;
public:
    MedianFinder(): size{0}, left{0}, right{0} {
        
    }
    
    void addNum(int num) {
        size++;
        list<int>::iterator next_it;
        if(size == 1) {
            median_it = l.insert(l.end(), num);
            left++;
        }
        else if(num > *median_it) {
            right++;
            next_it = next(median_it);
        }
        else {
            left++;
            next_it = l.begin();
        }
        while(size > 1) {
            if(next_it == l.end() || next_it == median_it) {
                l.insert(next_it, num);
                break;
            }
            else {
                if(*next_it >= num) {
                    l.insert(next_it, num);
                    break;
                }
                else {
                    next_it++;
                }
            }
        }
        if(left >= right) {
            if(left == right+2) {
                left--;
                right++;
                median_it = prev(median_it);
            }
            else {}
        }
        else {
            left++;
            right--;
            median_it = next(median_it);
        }
    }
    
    double findMedian() {
        if(size % 2) return *median_it;
        return (*median_it + *next(median_it)) / 2.0L;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */