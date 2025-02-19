class Solution(object):
    def maxArea(self, height):
        max_area = 0
        i = 0
        j = len(height) - 1

        while i != j:
            max_area = max(max_area, min(height[i], height[j]) * (j - i))
            if height[j] < height[i]:
                j -= 1
            else:
                i += 1
        
        return max_area
    
    # This is too brute-force and fails the time allowed since itv is aboutr O(n^2)
    def maxAreaBad(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area = 0
        max_possible = 0
        for i in range(len(height)):
            max_possible = height[i] * (len(height) - 1 - i)
            if max_area < max_possible:
                for j in range(len(height) - i):
                    if min(height[len(height) - 1 - j], height[i]) * ((len(height) - 1 - j) - i) > max_area:
                        max_area = min(height[len(height) - 1 - j], height[i]) * ((len(height) - 1 - j) - i)
                        if max_area == max_possible:
                            break
        return max_area




if __name__ == '__main__':
    solution = Solution()
    print(solution.maxArea([1,8,6,2,5,4,8,3,7]))
     