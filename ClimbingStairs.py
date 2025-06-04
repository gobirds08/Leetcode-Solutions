class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        possibilities = 0

        if n == 1:
            return 1
        
        curr = {1: 1, 2: 1}

        if n == 2:
            curr = {1: 1}
            possibilities += 1


        while True:
            if not curr:
                break

            for key in list(curr.keys()):
                num_key = curr[key]
                del curr[key]
                if key + 1 in curr and key + 1 <= n:
                    if key + 1 == n:
                        possibilities += num_key
                    else:
                        curr[key + 1] += num_key
                elif key + 1 < n:
                    curr[key + 1] = num_key
                elif key + 1 == n:
                    possibilities += num_key

                if key + 2 in curr and key + 2 <= n:
                    if key + 2 == n:
                        possibilities += num_key
                    else:
                        curr[key + 2] += num_key
                elif key + 2 < n:
                    curr[key + 2] = num_key
                elif key + 2 == n:
                    possibilities += num_key

        
        return possibilities
    

if __name__ == '__main__':
    solution = Solution()
    solution.climbStairs(2)