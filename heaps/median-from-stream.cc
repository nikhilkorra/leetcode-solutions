// #typedef <pair<int, int> pi;
class MedianFinder {
public:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    MedianFinder() {
    }
    
    void addNum(int num) {
        l.push(num);
        if(l.size() - r.size() > 1){
            int leftTop = l.top();
            l.pop();
            r.push(leftTop);
            return;
        }
        if(r.size() > 0){
            int leftTop = l.top(), rightTop = r.top();
            if(leftTop > rightTop){
                l.pop(), r.pop();
                l.push(rightTop), r.push(leftTop);
            }
        }
        return;
    }
    
    double findMedian() {
        if(l.size() == r.size()){
            return (double)(l.top() + r.top())/2;
        }
        return l.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */