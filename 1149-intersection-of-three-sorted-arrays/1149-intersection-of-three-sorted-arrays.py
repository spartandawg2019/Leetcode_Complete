class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        result = []
        p1, p2, p3 = 0, 0, 0
        
        while p1 < len(arr1) and p2 < len(arr2) and p3 < len(arr3):
            if arr1[p1] == arr2[p2] == arr3[p3]:
                result.append(arr1[p1])
                p1 += 1
                p2 += 1
                p3 += 1
            else:
                smallest = min(arr1[p1], arr2[p2], arr3[p3])
                if arr1[p1] == smallest:
                    p1 += 1
                if arr2[p2] == smallest:
                    p2 += 1
                if arr3[p3] == smallest:
                    p3 += 1
        
        return result
