class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        '''
        we can save even more time by caching the powers of two for a divisor
        recall, we computed all powers of two for a divisor
        
        intuition:
            the property if that the difference will always be less than the previous double of the divisor that fits into it
            if it were equal or bigger, than the largest doubling, then we must have stopped the doubling too sonon
        '''
        is_negative = (dividend < 0) != (divisor < 0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        
        doubles = []
        powersOfTwo = []
        
        powerOfTwo = 1
        
        while divisor <= dividend:
            doubles.append(divisor)
            powersOfTwo.append(powerOfTwo)
            divisor = divisor << 1
            powerOfTwo = powerOfTwo << 1
        
        #no go backwards and try seeing if the largest double fits into the divident
        quotient = 0
        N = len(doubles)
        for i in range(N-1,-1,-1):
            if doubles[i] <= dividend:
                quotient += powersOfTwo[i]
                dividend -= doubles[i]
                
        
        return min(2147483647, max(-quotient if is_negative else quotient, -2147483648))