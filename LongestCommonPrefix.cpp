#include <string>
#include <vector>

class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            const std::size_t LEN_STRING_ARR = strs.size();
            if (LEN_STRING_ARR == 0) {
                return "";
            }

            std::string longest_prefix = strs[0];
            for (int i = 1; i < LEN_STRING_ARR; i++) {
                std::string word = strs[i];
                if (word.size() > longest_prefix.size()) {
                    word = word.substr(0, longest_prefix.size());
                }

                size_t j = longest_prefix.size() - 1;
                while (word != longest_prefix) {
                    word = word.substr(0, j);
                    longest_prefix = longest_prefix.substr(0, j);
                    j--;
                }
            }

            return longest_prefix;
        }
};