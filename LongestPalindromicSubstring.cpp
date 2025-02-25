#include <string>
#include <iostream>

class Solution {
    public:
        std::string longestPalindrome(std::string s) {
           std::string longest = "";
           size_t LEN_S = s.size();
           for (size_t i = 0; i < LEN_S; i++){
                std::string first = longestSubstringPalindrome(i, i, s, LEN_S);
                std::string second = i + 1 < LEN_S ? longestSubstringPalindrome(i, i + 1, s, LEN_S) : "";
                size_t first_size = first.size();
                size_t second_size = second.size();

                if (first_size > second_size){
                    if (first_size > longest.size()){
                        longest = first;
                    }
                }else {
                    if(second_size > longest.size()){
                        longest = second;
                    }
                }
           }

           return longest;
        }
    
    private:
        std::string longestSubstringPalindrome(int left, int right, std::string s, size_t len_s){
            while (left >= 0 && right < len_s){
                if (s[left] != s[right]){
                    break;
                }
                left--;
                right++;
            }

            std::string long_subst = s.substr(left + 1, right - left - 1);
            return long_subst;
        }
};

int main(){
    Solution solution;
    std::string s = "xaabacxcabaaxcabaax";
    std::cout << solution.longestPalindrome(s) << std::endl;
    return 0;
}