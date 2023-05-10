class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res = []
        i = 0
        while i < len(words):
            j = i
            num_of_letters = 0
            while j < len(words) and num_of_letters + len(words[j]) + (j - i) <= maxWidth:
                num_of_letters += len(words[j])
                j += 1
            cur = words[i:j]
            if j == len(words):
                res.append(" ".join(cur) + " " * (maxWidth - num_of_letters - (j - i - 1)))
            else:
                spaces = maxWidth - num_of_letters
                for k in range(spaces):
                    cur[k % (len(cur) - 1 or 1)] += " "
                res.append("".join(cur))
            i = j
        return res
