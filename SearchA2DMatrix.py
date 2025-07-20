class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        NUM_ROWS = len(matrix)
        NUM_COLS = len(matrix[0])

        l, r = 0, NUM_ROWS * NUM_COLS - 1

        while l <= r:
            m = (r + l) // 2

            row, col = m // NUM_COLS, m % NUM_COLS

            val = matrix[row][col]

            if val == target:
                return True

            if val > target:
                r = m - 1 
            else:
                l = m + 1
            
            

        return False
