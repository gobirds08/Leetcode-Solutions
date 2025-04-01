#include <vector>

class Solution {
    public:
        std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
            std::vector<std::vector<int>> output;
            output.push_back(std::vector<int>());
            for (int num : nums) {
                std::vector<std::vector<int>> currentOutput = output; 
                for (const auto& temp : currentOutput) {
                    std::vector<int> copy(temp);
                    copy.push_back(num);
                    output.push_back(copy);
                }
            }

            return output;
        }
};