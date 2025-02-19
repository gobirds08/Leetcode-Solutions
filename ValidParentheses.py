class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for letter in s:
            if letter == ")":
                if len(stack) == 0 or stack.pop() != "(":
                    return False
            elif letter == "}":
                if len(stack) == 0 or stack.pop() != "{":
                    return False
            elif letter == "]":
                if len(stack) == 0 or stack.pop() != "[":
                    return False
            else:
                stack.append(letter)

        if len(stack) != 0:
            return False
        return True
    
if __name__ == '__main__':
    solution = Solution()
    print(solution.isValid("([])"))