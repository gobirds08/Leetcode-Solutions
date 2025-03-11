#include <string>
#include <set>

class Solution {
    public:
        int numberOfSubstrings(std::string s) {
            int num_subs = 0;
            const std::size_t S_SIZE = s.size();
            std::set<char> chars_set;

            for (int i = 0; i < S_SIZE - 2; i++) {
                chars_set.insert(s[i]);
                for (int j = i + 1; j < S_SIZE; j++) {
                    chars_set.insert(s[j]);
                    if (chars_set.find('a') != chars_set.end() && chars_set.find('b') != chars_set.end() && chars_set.find('c') != chars_set.end()) {
                        num_subs += S_SIZE - j;
                        break;
                    }
                }
                chars_set.clear();
            }

            return num_subs;
        }
};

int main() {
    Solution solution;
    solution.numberOfSubstrings("abcabc");
}