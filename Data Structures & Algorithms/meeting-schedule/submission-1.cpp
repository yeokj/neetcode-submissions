/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;

        sort(intervals.begin(), intervals.end(), [](const Interval &a, Interval &b) {
            if (a.start != b.start) return a.start < b.start;
        });
        int prevMeet = intervals[0].end, n = intervals.size();

        for (int i = 1; i < n; ++i) {
            int currStart = intervals[i].start;

            if (prevMeet > currStart) {
                return false;
            }
            else {
                prevMeet = intervals[i].end;
            }
        }
        return true;
    }
};
