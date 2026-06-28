class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 1) return cost[0];
        if (cost.size() == 2) return min(cost[0], cost[1]);

        int costOne = cost[0], costTwo = cost[1];
        int n = cost.size();

        for (int i = 2; i < n; ++i) {
            int temp = cost[i] + min(costOne, costTwo);
            costOne = costTwo;
            costTwo = temp;
        }
        return min(costOne, costTwo);
    }
};
