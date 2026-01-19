#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>

class Solution {

    private:
        

        void backtrack(std::vector<std::vector<int>>& result, std::unordered_map<int, bool>& used_map, std::vector<int>& candidates, const int target, std::vector<int> choose_index, int sum) {
            if (sum > target) {
                return ;
            } else if (sum == target) {
                std::vector<int> m;
                for (int i = 0; i < choose_index.size(); i++) {
                    m.push_back(candidates[choose_index[i]]);
                }
                result.push_back(m);
                return ;
            }
            int i = choose_index.back() + 1;
            for (;i < candidates.size(); i++) {
                if (used_map[candidates[i]] == true) {
                    continue;
                }
                std::vector<int> tmp_choose_index(choose_index);
                tmp_choose_index.push_back(i);

                backtrack(result, used_map, candidates, target, tmp_choose_index, sum + candidates[i]);
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
                std::vector<int> tmp_choose_index;
                tmp_choose_index.push_back(i);
                backtrack(result, used_num, candidates, target, tmp_choose_index, candidates[i]);
                used_num[candidates[i]] = true;
            }
            return result;
        }
};