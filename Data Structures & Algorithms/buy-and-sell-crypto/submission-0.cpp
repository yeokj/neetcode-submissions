class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        int profit;

        for (const auto &price : prices) {
            if (price < minPrice) {
                minPrice = price;
            }
            else {
                profit = price - minPrice;
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};
