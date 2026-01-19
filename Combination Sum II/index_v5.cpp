#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <map>

class Solution {

    private:
        

        void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& candidates, const int target, std::vector<int>& choose_index, int sum) {
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
            

            for (int i = choose_index.back() + 1; i < candidates.size(); i++) {
                if (i > choose_index.back() + 1 && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                choose_index.push_back(i);
                backtrack(result, candidates, target, choose_index, sum + candidates[i]);
                choose_index.pop_back();
            }
            
            
        }
    public:
        std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
            std::vector<std::vector<int>> result;
            
            std::sort(candidates.begin(), candidates.end());
            for (int i = 0; i < candidates.size(); i++) {
                if (i > 0 && candidates[i] == candidates[i - 1]) {
                    continue;   //edge case
                }
                std::vector<int> choose_index_list;
                choose_index_list.push_back(i);
                
                backtrack(result, candidates, target, choose_index_list, candidates[i]);
            }

            return result;
            
        }
};