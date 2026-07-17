class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1], result = 0, n = intervals.size();

        for (int i = 1; i < n; ++i) {
            int currStart = intervals[i][0];

            if (prevEnd > currStart) { 
                ++result;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else { 
                prevEnd = intervals[i][1];
            }
        }
        return result;
    }
};
