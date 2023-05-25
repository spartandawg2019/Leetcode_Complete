class Solution:
    def findClosestElements(self, arr, k, x):
        n = len(arr)
        low = 0
        high = n - k
        
        while low < high:
            mid = low + (high - low) // 2
            if x - arr[mid] > arr[mid + k] - x:
                low = mid + 1
            else:
                high = mid
        
        result = arr[low : low + k]
        return result
