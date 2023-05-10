class Solution:
    def reverseWords(self, s: str) -> str:
        # remove leading and trailing spaces
        s = s.strip()
        # reverse the entire string
        s = s[::-1]
        # reverse each word
        start = 0
        for i in range(len(s)):
            if s[i] == ' ':
                s = s[:start] + s[start:i][::-1] + s[i:]
                start = i + 1
        # reverse the last word
        s = s[:start] + s[start:][::-1]
        # remove extra spaces
        s = ' '.join(s.split())
        return s
