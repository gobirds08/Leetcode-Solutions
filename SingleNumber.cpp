#include <vector>
#include <algorithm>

class Solution {
    public:
        int singleNumber(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());

            std::size_t i = 0;
            
            while (true) {
                if (!(i + 1 < nums.size()) || !(nums[i] == nums[i + 1])) {
                    return nums[i];
                }
                i += 2;
            }
            
        }
};