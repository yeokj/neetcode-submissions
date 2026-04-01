class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp = defaultdict(int)

        for c in s:
            mp[c] += 1

        for c in t:
            if c not in mp:
                return False
            mp[c] -= 1

        for v in mp.values():
            if v != 0:
                return False

        return True