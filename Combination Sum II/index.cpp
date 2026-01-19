#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <map>

class Solution {

    private:
        
        /**
         * @brief 
         * Define backtrack function 
         * pass pointer for result and num_path, not copy value
         * @param result 
         * @param candidates 
         * @param target 
         * @param choose_index 
         * @param sum 
         */
        void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& candidates, const int target, std::vector<int>& num_path, int sum) {
            if (sum > target) {
                return;
            } else if (sum == target) {
                std::vector<int> answer;
                for (int i : num_path) {    // O(N)
                    answer.push_back(candidates[i]);
                }
                result.push_back(answer);
                return;
            }

            // the next number, minimum  is the choose position + 1
            int start_position = num_path.back() + 1;

            
            for (int i = start_position; i < candidates.size(); i++) {  // O (N)
                if (i > start_position && candidates[i] == candidates[i - 1] || candidates[i] > target) {
                    continue;
                }

                num_path.push_back(i);
                this->backtrack(result, candidates, target, num_path, sum + candidates[i]);
                num_path.pop_back();
            }
        }
    public:
        std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
            // define result
            std::vector<std::vector<int>> result;
            
            // sort andiates, make possiable can easy different
            std::sort(candidates.begin(), candidates.end());    // O(N log N)

            for (int i = 0; i < candidates.size(); i++) {   // O(N)
                if (i > 0 && candidates[i] == candidates[i - 1] || candidates[i] > target) {  // skip repeat
                    continue;
                }

                std::vector<int> num_path;  // define vector for record num_path, but it index
                num_path.push_back(i);
                this->backtrack(result, candidates, target, num_path, candidates[i]);
                num_path.pop_back();
            }

            return result;
        }
};