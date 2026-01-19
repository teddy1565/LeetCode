#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

class Solution {

    private:
        

        void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& candidates, const int target, std::vector<int> choose_index, int sum) {
            if (sum > target) {
                return;
            }
            for (int i = 0; i < candidates.size(); i++) {
                std::vector<int> tmp_choose_index(0, candidates.size());
                if (choose_index[i] == 1) {
                    continue;
                }
                
                
            }
        }
    public:
        std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
            std::vector<int> choose_index_list(0, candidates.size());
            std::vector<std::vector<int>> result;
            backtrack(result, candidates, target, choose_index_list, 0);
            return result;
        }
};