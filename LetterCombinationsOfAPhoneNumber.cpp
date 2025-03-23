#include <vector>
#include <string>
#include <map>

class Solution {
    public:
        std::vector<std::string> letterCombinations(std::string digits) {
            const std::map<int, std::vector<char>> digit_vals {{2, {'a', 'b', 'c'}}, {3, {'d', 'e', 'f'}}, {4, {'g', 'h', 'i'}}, 
            {5, {'j', 'k', 'l'}}, {6, {'m', 'n', 'o'}}, {7, {'p', 'q', 'r', 's'}}, {8, {'t', 'u', 'v'}}, {9, {'w', 'x', 'y', 'z'}}};
            std::vector<std::string> output;
            for (char s : digits) {
                const std::vector<char> letters = digit_vals.at(s - '0');
                std::vector<std::string> temp;
                if (output.size() != 0) {
                    for (char letter : letters) {
                        for (std::string combo : output) {
                            temp.push_back(combo + letter);
                        }
                    }
                    output = temp;
                } else{
                    for (char letter : letters) {
                        output.push_back(std::string(1, letter));
                    }
                }
            }
        return output;
    }
};

int main() {
    Solution solution;
    solution.letterCombinations("23");
}