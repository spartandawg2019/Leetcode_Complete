class Solution extends GuessGame {
    def guessNumber(n: Int): Int = {
        var left = 1
        var right = n
        while (left <= right) {
            val mid = left + (right - left) / 2
            val result = guess(mid)
            if (result == 0) {
                return mid
            } else if (result == -1) {
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        return -1
    }
}
