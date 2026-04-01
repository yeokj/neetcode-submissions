class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return []

        mp = {}
        
        for i, num in enumerate(nums):
            diff = target - num
            if diff not in mp:
                mp[num] = i
            else:
                return [mp[diff], i]

        return []
        