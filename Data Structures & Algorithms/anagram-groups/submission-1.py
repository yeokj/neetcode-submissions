class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) <= 1:
            return [strs]

        mp = defaultdict(list)

        for word in strs:
            temp = tuple(sorted(word))
            mp[temp].append(word)
        
        return list(mp.values())
        
        
        
        