#include <vector>
#include <algorithm>


class Solution {
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            std::vector<std::vector<int>> values;
            const int NUMS_SIZE = nums.size();

            if (NUMS_SIZE < 3){
                return {};
            }

            std::sort(nums.begin(), nums.end());

            for (int i = 0; i < NUMS_SIZE; i++){
                if (nums[i] > 0){
                    break;
                }
                if (i == 0 || nums[i] != nums[i - 1]){
                    int left = i + 1;
                    int right = NUMS_SIZE - 1;
                    
                    while (left < right){
                        int sum = nums[i] + nums[left] + nums[right];
                        if (sum == 0){
                            values.push_back({nums[i], nums[left], nums[right]});
                            left++;
                            right--;
                            while (left < right && nums[left] == nums[left - 1]){
                                left++;
                            }
                        } else if (sum < 0){
                            left++;
                        } else {
                            right--;
                        }
                        
                    }
                }
            }
            return values;
        }
};

int main(){
    Solution solution;
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    solution.threeSum(nums);
    return 0;
}