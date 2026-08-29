class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long result = 0;

        while (k > 0) {
            int top = pq.top();
            pq.pop();
            pq.push(static_cast<int>(sqrt(top)));
            --k;
        }

        while (!pq.empty()) {
            int top = pq.top();
            pq.pop();
            result += top;
        }
        return result;
    }
};