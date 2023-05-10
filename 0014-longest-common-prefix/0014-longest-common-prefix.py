class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        prefix = strs[0]
        for word in strs[1:]:
            i = 0
            while i < len(word) and i < len(prefix) and word[i] == prefix[i]:
                i += 1
            prefix = prefix[:i]
            if not prefix:
                break
        return prefix
