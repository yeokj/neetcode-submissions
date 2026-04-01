class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right, low = 0, len(nums) - 1, nums[0]

        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid - 1
            low = min(low, nums[mid])

        return low 