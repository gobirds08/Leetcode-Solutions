#include <vector>
#include <algorithm>

class Solution {
    public:
        int singleNumber(std::vector<int>& nums) {
            int xor_acc = 0;
            for (int num : nums) {
                xor_acc ^= num;
            }
            return xor_acc;
        }
};