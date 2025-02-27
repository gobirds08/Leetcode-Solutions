#include <vector>
#include <string>
#include <unordered_map>

class Solution {
    public:
        std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
            std::vector<int> output;
            if (words.empty() || s.empty()) {
                return output;
            }
            const size_t WORD_LEN = words[0].size();
            const size_t NUM_WORDS = words.size();
            const size_t TOTAL_LEN = WORD_LEN * NUM_WORDS;
            
            if (s.size() < TOTAL_LEN) {
                return output;
            }
            std::unordered_map<std::string, int> word_count;
            for (const std::string& word : words) {
                word_count[word]++;
            }

            for (size_t i = 0; i < WORD_LEN; i++) {
                size_t left = i;
                size_t right = i;
                size_t count = 0;
                std::unordered_map<std::string, int> seen;
    
                while (right + WORD_LEN <= s.size()) {
                    std::string word = s.substr(right, WORD_LEN);
                    right += WORD_LEN;
    
                    if (word_count.find(word) != word_count.end()) {
                        seen[word]++;
                        count++;
    
                        while (seen[word] > word_count[word]) {
                            std::string leftWord = s.substr(left, WORD_LEN);
                            seen[leftWord]--;
                            count--;
                            left += WORD_LEN;
                        }
    
                        if (count == NUM_WORDS) {
                            output.push_back(left);
                        }
                    } else {
                        seen.clear();
                        count = 0;
                        left = right;
                    }
                }
            }
    
            return output;
        }
    };

int main(){
    Solution solution;
    std::string s = "barfoofoobarthefoobarman";
    std::vector<std::string> words {"bar", "foo", "the"};
    solution.findSubstring(s, words);
}