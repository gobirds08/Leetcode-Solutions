#include <vector>

class Solution {
    public:
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
            std::size_t nums1_index = 0;
            std::size_t nums2_index = 0;

            std::vector<int> nums1_copy(nums1);
            
            while (true) {
                if (nums1_index < m && nums2_index < n) {
                    if (nums1_copy[nums1_index] <= nums2[nums2_index]) {
                        nums1[nums1_index + nums2_index] = nums1_copy[nums1_index];
                        nums1_index++;
                    } else {
                        nums1[nums1_index + nums2_index] = nums2[nums2_index];
                        nums2_index++;
                    }
                } else if (nums1_index < m) {
                    nums1[nums1_index + nums2_index] = nums1_copy[nums1_index];
                    nums1_index++;
                } else if (nums2_index < n) {
                    nums1[nums1_index + nums2_index] = nums2[nums2_index];
                    nums2_index++;
                } else {
                    break;
                }
            }
        }
};