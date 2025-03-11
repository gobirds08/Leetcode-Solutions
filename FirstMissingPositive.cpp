#include <vector>
#include <algorithm>

class Solution {
    public:
        int firstMissingPositive(std::vector<int>& nums) {
            int smallest_num = 1;

            std::sort(nums.begin(), nums.end());
            
            for (int num: nums) {
                if (num == smallest_num) {
                    smallest_num = num + 1;
                }
            }

            return smallest_num;
        }
};