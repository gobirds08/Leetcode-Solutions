#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
    public:
        std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
            
            std::sort(intervals.begin(), intervals.end());
            intervals.erase(std::unique(intervals.begin(), intervals.end()), intervals.end());

            std::vector<std::vector<int>> output;

            for (auto interval : intervals) {
                bool found = false;
                for (auto& checked_interval : output) {
                    if ((interval[0] >= checked_interval[0] && interval[0] <= checked_interval[1]) || (interval[1] <= checked_interval[1] && interval[1]  >= checked_interval[0]) || (interval[0] <= checked_interval[0] && interval[1] >= checked_interval[1])) {
                        checked_interval[0] = std::min(interval[0], checked_interval[0]);
                        checked_interval[1] = std::max(interval[1], checked_interval[1]);
                        found = true;
                    }
                }

                if (!found) {
                    output.push_back(interval);
                }
            }

            return output;
        }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> input {{1, 4}, {0, 4}};
    solution.merge(input);
}