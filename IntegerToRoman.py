class Solution(object):
    def intToRoman(self, num):
        numerals = {1000: "M", 500: "D", 100: "C", 50: "L", 10: "X", 5: "V", 1: "I"}
        numeral = 1000
        final_numeral = ""
        while numeral > 0:
            curr_val = num // numeral
            num = num % numeral
            if curr_val == 9: 
                final_numeral += numerals[int(numeral)] + numerals[int(numeral) * 10]
            elif curr_val == 4:
                final_numeral += numerals[int(numeral)] + numerals[int(numeral) * 5]
            else:
                if curr_val >= 5:
                    final_numeral += numerals[int(numeral) * 5] + (int(curr_val - 5) * numerals[int(numeral)] )
                else:
                    final_numeral += int(curr_val) * numerals[int(numeral)]
            numeral = int(numeral / 10)
        return final_numeral


if __name__ == '__main__':
    solution = Solution()
    print(solution.intToRoman(58))