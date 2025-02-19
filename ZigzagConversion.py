# BAD RUNTIME - LIKE ABSOLUTELY AWFUL

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if len(s) <= numRows or numRows <= 1:
            return s
        list_str = []
        curr_list = []
        top = False
        for i in range(len(s)):
            calc =  i % (numRows - 1) == 0
            if calc and not top:
                curr_list.append(s[i])
                top = True
            elif calc and top:
                curr_list.append(s[i])
                list_str.append(curr_list)
                curr_list = []
                top = False
            elif not top:
                remainder = i % (numRows - 1)
                for j in range(numRows):
                    if j == (numRows - 1 - remainder):
                        curr_list.append(s[i])
                    else:
                        curr_list.append(" ")
                list_str.append(curr_list)
                curr_list = []
            else:
                curr_list.append(s[i])

        if len(curr_list) != 0:
            list_str.append(curr_list)
        

        final_str = ""
        for i in range(numRows):
            for j in range(len(list_str)):
                if len(list_str[j]) - 1 >= i and list_str[j][i] != " ":
                    final_str += list_str[j][i]

        return final_str


if __name__ == '__main__':
    solution = Solution()
    print(solution.convert("PAYPALISHIRING", 4))