class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if (q.empty()) return 0;

        int n = q.size() - 1;
        while (n > 0) {
            q.push(q.front());
            q.pop();
            --n;
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        if (q.empty()) return 0;
        int x = pop();
        q.push(x);
        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */