class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for (char c : tasks) {
            ++mp[c];
        }

        priority_queue<int> pq;
        queue<pair<int, int>> q;

        for (const auto &p : mp) {
            pq.push(p.second);
        }

        int currentTime = 0;

        while (!pq.empty() || !q.empty()) {
            if (!q.empty()) {
                int availableTime = q.front().second;
                if (availableTime <= currentTime) {
                    pq.push(q.front().first);
                    q.pop();
                }
            }

            if (!pq.empty()) {
                int count = pq.top();
                pq.pop();
                --count;

                if (count > 0) {
                    q.push({count, currentTime + n + 1});
                }
            }
            ++currentTime;
        }

        return currentTime;
    }
};
