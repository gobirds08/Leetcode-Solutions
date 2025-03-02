#include <vector>
#include <cstddef>

class Solution {
    public:
        int removeElement(std::vector<int>& nums, int val) {
            size_t NUMS_SIZE = nums.size();
            size_t i = 0;
            size_t open_index = 0;
            while (i < NUMS_SIZE) {
                if (nums[i] != val) {
                    nums[open_index] = nums[i];
                    open_index++;
                }
                i++;
            }

            return open_index;
        }
};

int main(){
    Solution solution;
    std::vector<int> nums {0,1,2,2,3,0,4,2};
    solution.removeElement(nums, 2);
}