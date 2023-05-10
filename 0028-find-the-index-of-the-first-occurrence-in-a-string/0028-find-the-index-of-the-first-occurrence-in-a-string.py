class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        hlen = len(haystack)
        nlen = len(needle)
        if nlen == 0:
            return 0
        if hlen < nlen:
            return -1
        for i in range(hlen - nlen + 1):
            j = 0
            while j < nlen:
                if haystack[i+j] != needle[j]:
                    break
                j += 1
            if j == nlen:
                return i
        return -1
