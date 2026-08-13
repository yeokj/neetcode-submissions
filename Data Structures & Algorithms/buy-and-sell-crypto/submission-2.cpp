class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        int profit;

        for (const auto &price : prices) {
            minPrice = min(minPrice, price);
            profit = price - minPrice;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
