class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = defaultdict(int)

        for num in nums:
            mp[num] += 1

        bucket = [[] for _ in range(len(nums) + 1)]

        for key, val in mp.items():
            bucket[val].append(key)

        result = []

        for i in range(len(nums), 0, -1):
            for num in bucket[i]:
                result.append(num)
                if len(result) == k:
                    return result
        
        return result
        
            