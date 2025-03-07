#include <vector>
#include <map>
#include <set>

class Solution {
    public:
        std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
            const std::size_t n = grid.size();
            std::set<int> values;
            int repeated = 0;
            int expec_accumulator = 0;
            int got_accumulator = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (values.find(grid[i][j]) != values.end()) {
                        repeated = grid[i][j];
                    } else {
                        values.insert(grid[i][j]);
                        got_accumulator += grid[i][j];
                    }
                    expec_accumulator += (i * n) + j + 1;
                }
            }

            int missing = expec_accumulator - got_accumulator;
        
            return {repeated, missing};    
        }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid {{9,1,7},{8,9,2},{3,4,6}};
    solution.findMissingAndRepeatedValues(grid);
}