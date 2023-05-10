class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        m = {}
        for c in magazine:
            if c in m:
                m[c] += 1
            else:
                m[c] = 1
        for c in ransomNote:
            if c in m and m[c] > 0:
                m[c] -= 1
            else:
                return False
        return True
