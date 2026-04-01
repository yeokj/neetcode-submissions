class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price, max_profit = prices[0], 0

        for price in prices:
            if price < min_price:
                min_price = price
            else :
                max_profit = max(max_profit, price - min_price)
        
        return max_profit