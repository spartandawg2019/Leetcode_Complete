class Solution:
    def myAtoi(self, s: str) -> int:
        # Step 1: Remove leading whitespaces
        s = s.lstrip()

        # Step 2: Check for sign
        sign = 1
        if s and (s[0] == '-' or s[0] == '+'):
            sign = -1 if s[0] == '-' else 1
            s = s[1:]

        # Step 3: Read in digits
        result = 0
        for c in s:
            if not c.isdigit():
                break
            result = result * 10 + int(c)

        # Step 4: Apply sign
        result *= sign

        # Step 5: Clamp result to 32-bit signed integer range
        INT_MIN = -2 ** 31
        INT_MAX = 2 ** 31 - 1
        if result < INT_MIN:
            return INT_MIN
        elif result > INT_MAX:
            return INT_MAX
        else:
            return result