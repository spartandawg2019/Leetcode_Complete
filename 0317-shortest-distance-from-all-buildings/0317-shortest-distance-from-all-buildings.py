from collections import deque
from typing import List

class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return -1

        m, n = len(grid), len(grid[0])
        distance = [[0] * n for _ in range(m)]
        reachable = [[0] * n for _ in range(m)]
        buildingCount = 0

        def bfs(row, col):
            visited = [[False] * n for _ in range(m)]
            queue = deque([(row, col, 0)])
            visited[row][col] = True

            while queue:
                r, c, dist = queue.popleft()
                for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    nr, nc = r + dr, c + dc
                    if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc]:
                        visited[nr][nc] = True
                        if grid[nr][nc] == 0:
                            distance[nr][nc] += dist + 1
                            reachable[nr][nc] += 1
                            queue.append((nr, nc, dist + 1))
                        elif grid[nr][nc] == 1:
                            continue
                        else:
                            # Obstacle
                            visited[nr][nc] = True

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    bfs(i, j)
                    buildingCount += 1

        minDistance = float('inf')
        found = False

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and reachable[i][j] == buildingCount:
                    if not found or distance[i][j] < minDistance:
                        minDistance = distance[i][j]
                    found = True

        return minDistance if found else -1
