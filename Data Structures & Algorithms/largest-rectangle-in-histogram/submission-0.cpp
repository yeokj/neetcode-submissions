class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int x;
        int y;
        int area;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                y = heights[st.top()];
                st.pop();
                if (st.empty()) {
                    x = i - (-1) - 1;
                }
                else {
                    x = i - st.top() - 1;
                }
                area = x * y;
                maxArea = max(maxArea, area);
            }
            st.push(i);
        }
        return maxArea;
    }
};
