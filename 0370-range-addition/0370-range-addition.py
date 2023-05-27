class Solution:
    def getModifiedArray(self, length: int, updates: List[List[int]]) -> List[int]:
        arr = [0] * length

        for update in updates:
            start, end, inc = update[0], update[1], update[2]

            arr[start] += inc

            if end + 1 < length:
                arr[end + 1] -= inc

        prefix_sum = 0

        for i in range(length):
            prefix_sum += arr[i]
            arr[i] = prefix_sum

        return arr
