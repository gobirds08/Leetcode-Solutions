from collections import deque

class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        queue = deque()
        fresh = 0
        minutes = -1
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    queue.append((i, j))
                elif grid[i][j] == 1:
                    fresh += 1

        queue.append((-1, -1))
        
        while queue:
            row, col = queue.popleft()
            if row == -1:
                minutes += 1
                if queue:
                    queue.append((-1, -1))
            else:
                for i in range(4):
                    new_row, new_col = row, col
                    if i == 0:
                        new_row += 1
                    elif i == 1:
                        new_row -= 1
                    elif i == 2:
                        new_col += 1
                    else:
                        new_col -= 1
                
                    if new_row >= 0 and new_row < len(grid) and new_col >= 0 and new_col < len(grid[0]) and grid[new_row][new_col] == 1:
                        fresh -= 1
                        queue.append((new_row, new_col))
                        grid[new_row][new_col] = 2

        if fresh != 0:
            return -1
        
        return minutes

        
if __name__ == '__main__':
    solution = Solution()
    solution.orangesRotting([[2,1,1],[1,1,0],[0,1,1]])