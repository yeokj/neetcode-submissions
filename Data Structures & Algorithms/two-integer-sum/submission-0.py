class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return None
        numb = {}
        for i, num in enumerate(nums):
            if target - num not in numb:
                numb[num] = i
            elif target - num in numb:
                return [numb[target - num], i]
        return None