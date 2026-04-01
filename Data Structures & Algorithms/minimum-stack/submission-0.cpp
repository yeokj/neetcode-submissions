class MinStack {
private:
    stack<int> mini;
    stack<int> st;
public:
    MinStack() {

    }
    
    void push(int val) {
        if (mini.empty() || val <= mini.top()) {
            mini.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if (!st.empty() && st.top() == mini.top()) {
            mini.pop();
        }
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        return st.empty() ? -1 : st.top();
    }
    
    int getMin() {
        return mini.empty() ? -1 : mini.top();
    }
};
