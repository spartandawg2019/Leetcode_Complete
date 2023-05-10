class Solution:
    def countAndSay(self, n: int) -> str:
        res = "1"
        for i in range(n-1):
            temp = ""
            count = 1
            for j in range(1, len(res)):
                if res[j] == res[j-1]:
                    count += 1
                else:
                    temp += str(count) + res[j-1]
                    count = 1
            temp += str(count) + res[-1]
            res = temp
        return res
