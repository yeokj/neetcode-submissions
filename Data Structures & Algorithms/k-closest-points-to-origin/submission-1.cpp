class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        vector<vector<int>> results;

        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist, points[i]});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            results.push_back(pq.top().second);
            pq.pop();
        }

        return results;
    }
};
