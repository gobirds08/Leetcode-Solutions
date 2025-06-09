class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        islands = 0
        row_len = len(grid)
        col_len = len(grid[0])

        for i in range(row_len):
            for j in range(col_len):
                if grid[i][j] == "1":
                    self.dfs(grid, i, j)
                    islands += 1
        
        return islands

    def dfs(self, grid, i, j):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != "1":
            return
        
        grid[i][j] = "0"

        self.dfs(grid, i + 1, j)
        self.dfs(grid, i - 1, j)
        self.dfs(grid, i, j + 1)
        self.dfs(grid, i, j - 1)



    # bfs but has stack overflow: max recursion depth exceeded. avoid recursion.

    # def numIslands(self, grid):
    #     """
    #     :type grid: List[List[str]]
    #     :rtype: int
    #     """
    #     islands = 0
    #     row_len = len(grid)
    #     col_len = len(grid[0])

    #     for i in range(row_len):
    #         for j in range(col_len):
    #             if grid[i][j] == "1":
    #                 self.bfs(grid, i, j, deque())
    #                 islands += 1

    #     return islands


    # def bfs(self, grid, i , j, queue):
    #     if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != "1":
    #         return
        
    #     grid[i][j] == "0"

    #     queue.append((i + 1, j))
    #     queue.append((i - 1, j))
    #     queue.append((i, j + 1))
    #     queue.append((i, j - 1))

    #     while queue:
    #         coords = queue.popleft()
    #         self.bfs(grid, coords[0], coords[1], queue)