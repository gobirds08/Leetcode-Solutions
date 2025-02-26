#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> diffs;
        helper_method(0, 0, n, "", diffs);
        return diffs;
    }

private:
    void helper_method(size_t num_open, size_t num_closed, size_t n, std::string curr_string, std::vector<std::string> &diffs){
        if (n == 0){
            while (num_open != num_closed){
                curr_string.push_back(')');
                num_closed++;
            }
            diffs.push_back(curr_string);
            return;
        }

        curr_string.push_back('(');
        helper_method(num_open + 1, num_closed, n - 1, curr_string, diffs);

        if (num_open > num_closed){
            curr_string.pop_back();
            curr_string.push_back(')');
            helper_method(num_open, num_closed + 1, n, curr_string, diffs);
        }
        return;
    }
};

int main(){
    Solution solution;
    solution.generateParenthesis(3);
    return 0;
}