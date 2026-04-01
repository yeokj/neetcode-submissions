class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i, j = 0, len(heights) - 1
        max_area = 0

        while i < j:
            width = j - i
            length = min(heights[i], heights[j])
            curr_area = width * length

            if heights[i] < heights[j]:
                i += 1
            else:
                j -= 1
            
            max_area = max(max_area, curr_area)

        return max_area