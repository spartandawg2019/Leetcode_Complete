class MedianFinder {
public:
MedianFinder() {

    }

void addNum(int num) {
    if(lower.size() == upper.size()) {
        if(upper.size() && num > upper.top()) {
            lower.push(upper.top());
            upper.pop();
            upper.push(num);
        } else {
            lower.push(num);
        }
    } else {
        if(num < lower.top()) {
            upper.push(lower.top());
            lower.pop();
            lower.push(num);
        } else {
            upper.push(num);
        }
    }
}

double findMedian() {
    if(lower.size() == upper.size()) {
        return (lower.top() + upper.top()) / 2.0;
    } else {
        return lower.top();
    }
}

private:
priority_queue<int, vector<int>, less<int>> lower;
priority_queue<int, vector<int>, greater<int>> upper;
};

/**

Your MedianFinder object will be instantiated and called as such:
MedianFinder* obj = new MedianFinder();
obj->addNum(num);
double param_2 = obj->findMedian();
*/