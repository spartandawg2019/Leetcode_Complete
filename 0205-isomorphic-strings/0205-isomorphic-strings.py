class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        mapping = {}
        for i in range(len(s)):
            if s[i] in mapping:
                if mapping[s[i]] != t[i]:
                    return False
            elif t[i] in mapping.values():
                return False
            else:
                mapping[s[i]] = t[i]
        return True
