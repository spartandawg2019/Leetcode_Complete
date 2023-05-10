class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        result = ""
        # make the strings of equal length by adding leading zeroes
        while len(a) < len(b):
            a = "0" + a
        while len(b) < len(a):
            b = "0" + b
        # start adding the digits from right to left
        for i in range(len(a)-1, -1, -1):
            sum = int(a[i]) + int(b[i]) + carry
            if sum == 2:
                carry = 1
                result = "0" + result
            elif sum == 3:
                carry = 1
                result = "1" + result
            else:
                carry = 0
                result = str(sum) + result
        if carry != 0:
            result = "1" + result
        return result
