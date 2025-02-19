class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        is_negative = x < 0
        list_x = list(str(x))
        if is_negative:
            list_x.remove("-")
        for i in range(int(len(list_x) / 2)):
            list_x[i], list_x[len(list_x) - i - 1] = list_x[len(list_x) - i - 1], list_x[i]
            print(list_x)
        new_x = int(("-" if is_negative else "") + "".join(list_x))
        if abs(new_x) >= pow(2, 31):
            return 0
        return new_x
    


if __name__ == '__main__':
    solution = Solution()
    result = solution.reverse(-123)
    print(result)