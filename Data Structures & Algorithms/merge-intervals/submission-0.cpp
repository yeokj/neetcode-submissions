class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {}; // Checks for empty vector

        // Sorts vector since it can be out of order
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int n = intervals.size();

        result.push_back(intervals[0]); // Holds first interval for comparison

        // Start at 1 since the first interval is inside the result vector
        for (int i = 1; i < n; ++i) {
            // Finds an overlap
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};