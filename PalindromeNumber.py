class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        string_x = str(x)
        string_check = len(string_x) // 2

        for i in range(string_check):
            if string_x[i] != string_x[len(string_x) - 1 - i]:
                return False
        
        return True