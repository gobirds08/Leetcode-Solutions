#include <vector>

class Solution {
    public:
        std::vector<int> plusOne(std::vector<int>& digits) {
            size_t i = 1;
            const size_t SIZE_DIGITS = digits.size();

            while (digits[SIZE_DIGITS - i] == 9) {
                if (i == SIZE_DIGITS) {
                    break;
                }
                digits[SIZE_DIGITS - i] = 0;
                i++;
            }

            if (i == SIZE_DIGITS && digits[SIZE_DIGITS - i] == 9) {
                digits[SIZE_DIGITS - i] = 0;
                digits.insert(digits.begin(), 1);
            } else {
                digits[SIZE_DIGITS - i]++;
            }

            return digits;
        }
};

int main() {
    Solution solution;
    std::vector<int> digits {9, 9};
    solution.plusOne(digits);
}