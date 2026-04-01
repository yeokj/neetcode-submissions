class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        duplicate = set()
        for num in nums:
            if num not in duplicate:
                duplicate.add(num)
            elif num in duplicate:
                return True
        return False
