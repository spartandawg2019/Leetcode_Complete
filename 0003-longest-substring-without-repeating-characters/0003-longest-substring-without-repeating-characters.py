class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # Initialize variables to keep track of longest substring
        max_len = 0
        start = 0
        char_dict = {}
        # Iterate through the string
        for i, c in enumerate(s):
            # If the current character is already in the dictionary, update the start
            if c in char_dict and start <= char_dict[c]:
                start = char_dict[c] + 1
            else:
                # Otherwise, update the max length
                max_len = max(max_len, i - start + 1)
        
            char_dict[c] = i
    
        return max_len
