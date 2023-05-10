class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        length = 0
        i = len(s) - 1

        # Trim the string
        while i >= 0 and s[i] == ' ':
            i -= 1

        # Iterate the string in reverse order
        while i >= 0 and s[i] != ' ':
            length += 1
            i -= 1

        return length
