class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1
        if abs(n) == 1:
            if n == -1:
                return 1 / x
            return x

        negative = False
        if n < 0:
            negative = True
        if n % 2 != 0:
            return self.myPow(x * x if not negative else (1 / (x * x)), abs(n // 2)) * x
        else:
            return self.myPow(x * x if not negative else (1 / (x * x)), abs(n // 2))

    
if __name__ == '__main__':
    solution = Solution()
    print(solution.myPow(8.95371, -1))