class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        needle_len = len(needle)
        haystack_len = len(haystack)
        for i in range(haystack_len):
            for j in range(needle_len):
                if i + j > haystack_len - 1 or haystack[i + j] != needle[j]:
                    break
                if j == needle_len - 1:
                    return i
        return -1
    



if __name__ == '__main__':
    solution = Solution()
    print(solution.strStr("a", "a"))