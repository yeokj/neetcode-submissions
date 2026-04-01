class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low, high = 1, max(piles)

        while low <= high:
            mid = low +(high - low) // 2
            totalHours = 0
            for pile in piles:
                totalHours += ((pile + mid - 1) // mid)
            if totalHours > h:
                low = mid + 1
            else:
                high = mid - 1
        
        return low