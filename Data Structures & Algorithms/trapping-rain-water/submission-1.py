class Solution:
    def trap(self, height: List[int]) -> int:
        i, j = 0, len(height) - 1
        max_left, max_right = 0, 0
        water = 0

        while i < j:
            if height[i] < height[j]:
                if height[i] < max_left:
                    water += (max_left - height[i])
                    i += 1
                else:
                    max_left = height[i]
                    i += 1
            else:
                if height[j] < max_right:
                    water += (max_right - height[j])
                    j -= 1
                else:
                    max_right = height[j]
                    j -= 1
        
        return water