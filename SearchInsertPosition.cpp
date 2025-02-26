#include <vector>
#include <cmath>
#include <iostream>

class Solution {
    public:
        int searchInsert(std::vector<int>& nums, int target) {
            // const size_t NUMS_SIZE = nums.size();
            size_t lower = 0;
            size_t upper = nums.size() - 1;
            size_t i = floor(upper / 2);
            if(target > nums[upper]){
                return upper + 1;
            }

            if(target < nums[lower]){
                return 0;
            }

            while (true) {
                if (nums[i] == target){
                    return i;
                } else if (upper - lower == 1){
                    if(nums[lower] >= target){
                        return lower;
                    } else if (target > nums[upper]){
                        return upper + 1;
                    }else{
                        return upper;
                    }
                } else if (upper - lower == 0) {
                    if (nums[upper] < target){
                        return upper + 1;
                    }else{
                        return lower;
                    }
                } else if (nums[i] < target) {
                    lower = i + 1;
                } else {
                    upper = i - 1;
                }

                i = floor(upper - ((upper - lower) / 2));
            }
        }
};


int main(){
    Solution solution;
    std::vector<int> nums = {3, 5, 7, 9, 10};
    std::cout << solution.searchInsert(nums, 8) << std::endl;
}