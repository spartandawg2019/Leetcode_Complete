class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        in_degree = [0] * n
        for edge in edges:
            in_degree[edge[1]] += 1
        return [i for i in range(n) if in_degree[i] == 0]
