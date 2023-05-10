from typing import List
from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        m = len(words)
        wl = len(words[0])

        permutations = Counter(words)

        result = []
        for i in range(n - m * wl + 1):
            seen = Counter()
            j = 0
            while j < m:
                word = s[i + j * wl:i + (j + 1) * wl]
                if word in permutations:
                    seen[word] += 1
                    if seen[word] > permutations[word]:
                        break
                else:
                    break
                j += 1
            if j == m:
                result.append(i)

        return result
