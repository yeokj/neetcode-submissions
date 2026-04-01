class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() >= 2) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            int diff = x - y;

            if (diff > 0) {
                pq.push(diff);
            }
        }

        if (pq.size() == 0) {
            return 0;
        }

        return pq.top();
    }
};
