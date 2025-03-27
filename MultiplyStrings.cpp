#include <string>
#include <math.h>
#include <iostream>

class Solution {
    public:
        std::string multiply(std::string num1, std::string num2) {
            long num_one = 0;
            long num_two = 0;
            const std::size_t LEN_NUM1 = num1.size(); 
            const std::size_t LEN_NUM2 = num2.size(); 
            std::size_t max_len = LEN_NUM1;

            if (LEN_NUM1 < LEN_NUM2) {
                max_len = LEN_NUM2;
            }

            int i = max_len - 1;

            while (i >= 0) {
                if (i < LEN_NUM1) {
                    num_one += string_to_int(num1[i]) * pow(10, LEN_NUM1 - i - 1);
                }

                if (i < LEN_NUM2) {
                    num_two += string_to_int(num2[i]) * pow(10, LEN_NUM2 - i - 1);
                }
                i--;
            }

            return std::to_string((long long)num_one * num_two);
        }

    private:
        int string_to_int(char digit) {
            switch (digit) {
                case '0':
                    return 0;
                case '1':
                    return 1;
                case '2':
                    return 2;
                case '3':
                    return 3;
                case '4':
                    return 4;
                case '5':
                    return 5;
                case '6':
                    return 6;
                case '7':
                    return 7;
                case '8':
                    return 8;
                case '9': 
                    return 9;
                default:
                    return -1;
            }
        }
};

int main() {
    Solution solution;
    std::string result = solution.multiply("123", "4567");
    std::cout << result;
}

