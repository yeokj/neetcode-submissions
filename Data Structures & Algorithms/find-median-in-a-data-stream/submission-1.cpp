class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> highStream;
    priority_queue<int> lowStream;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lowStream.push(num);
        int val = lowStream.top();
        lowStream.pop();
        highStream.push(val);

        if (highStream.size() > lowStream.size()) {
            val = highStream.top();
            highStream.pop();
            lowStream.push(val);
        }
    }
    
    double findMedian() {
        if (lowStream.size() > highStream.size()) return (double)lowStream.top();
        if (lowStream.size() < highStream.size()) return (double)highStream.top();
        return (highStream.top() + lowStream.top()) / 2.0;
    }
};
