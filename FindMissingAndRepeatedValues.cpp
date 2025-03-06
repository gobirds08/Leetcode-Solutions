#include <vector>
#include <map>

class Solution {
    public:
        std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
            const std::size_t n = grid.size();
            std::map<int, int> values;
            
            for (int i = 1; i <= n * n; i++) {
                values.insert({i, 0});
            }

            for (auto arr : grid) {
                for (auto num: arr) {
                    values[num]++;
                }
            }

            int repeated = 0;
            int missing = 0;
            for (auto pair : values) {
                if (pair.second == 0) {
                    missing = pair.first;
                } else if (pair.second == 2) {
                    repeated = pair.first;
                }
            }

            return {repeated, missing};
        }
};