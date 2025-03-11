#include <vector>
#include <algorithm>

class Solution {
    public:
        int firstMissingPositive(std::vector<int>& nums) {
            const size_t NUMS_SIZE = nums.size();
            std::vector<bool> seen(NUMS_SIZE, false);
            
            for (int num: nums) {
                if (num > 0 && num <= NUMS_SIZE) {
                    seen[num - 1] = true;
                }
            }

            for (std::size_t i = 0; i < NUMS_SIZE; i++) {
                if (!seen[i]) {
                    return i + 1;
                }
            }

            return NUMS_SIZE + 1;
        }
};

int main() {
    Solution solution;
    std::vector<int> nums {1,2,0};
    solution.firstMissingPositive(nums);
}