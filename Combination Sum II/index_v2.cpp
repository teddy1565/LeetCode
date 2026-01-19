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
            } else if (sum == target) {
                result.push_back(choose_index);
                return;
            }

            for (int i = choose_index.back() + 1; i < candidates.size(); i++) {
                backtrack(result, candidates, target, choose_index, sum + choose_index[i]);
            }
        }
    public:
        std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
            
            std::vector<std::vector<int>> result;
            std::unordered_map<int, bool> used_num;
            for (int i = 0; i < candidates.size(); i++) {
                used_num[candidates[i]] = false;
            }
            for (int i = 0; i < candidates.size(); i++) {
                if (used_num[candidates[i]] == true) {
                    continue;
                }
                std::vector<int> choose_index_list;
                choose_index_list.push_back(i);

                backtrack(result, candidates, target, choose_index_list, candidates[i]);
                used_num[candidates[i]] = true;
            }
            return result;
        }
};