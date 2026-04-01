class Solution:
    def isValid(self, s: str) -> bool:
        mp = {
            ')':'(', '}':'{', ']':'['
        }
        st = []

        for c in s:
            if c not in mp:
                st.append(c)
            else:
                if not st or st[-1] != mp[c]:
                    return False
                st.pop()
        
        return len(st) == 0
