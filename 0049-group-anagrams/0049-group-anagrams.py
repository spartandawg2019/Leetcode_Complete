class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        map = {}
        ans = []
        for s in strs:
            temp = ''.join(sorted(s))
            if temp in map:
                map[temp].append(s)
            else:
                map[temp] = [s]
        for k, v in map.items():
            ans.append(v)
        return ans

if __name__ == '__main__':
    strs = ["eat","tea","tan","ate","nat","bat"]
    ret = Solution().groupAnagrams(strs)
    for vec in ret:
        for s in vec:
            print(s, end=' ')
        print()
