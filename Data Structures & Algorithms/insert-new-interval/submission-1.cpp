class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return {{newInterval[0], newInterval[1]}};

        vector<vector<int>> result;
        int start = newInterval[0], end = newInterval[1];
        int n = intervals.size();

        for (int i = 0; i < n; ++i) {
            if (intervals[i][1] < start) {
                result.push_back(intervals[i]);
            }
            else if (intervals[i][0] > end) {
                result.push_back({start, end});
                result.insert(result.end(), intervals.begin() + i, intervals.end());
                return result;
            }
            else {
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }

        result.push_back({start, end});
        return result;
    }
};
