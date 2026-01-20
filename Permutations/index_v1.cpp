#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

class Solution {
    private:
        void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& nums, std::vector<int>& path, std::unordered_map<int, int>& hash_path) {
            if (path.size() == nums.size()) {
                result.push_back(path);
                return;
            } else if (path.size() > nums.size()) {
                return;
            }

            for (int i = 0; i < nums.size(); i++) {
                
                if (hash_path[nums[i]] == i) {
                    continue;
                }
                hash_path[nums[i]] = i;
                path.push_back(i);
                this->backtrack(result, nums, path, hash_path);
                path.pop_back();
                hash_path[nums[i]] = -1;
            }
        }
    public:
        std::vector<std::vector<int>> permute(std::vector<int>& nums) {
            std::vector<std::vector<int>> result;
            std::vector<int> path;
            std::unordered_map<int, int> hash_path;
            for (int i = 0; i < nums.size(); i++) {
                hash_path[nums[i]] = -1;
            }

            for (int i = 0; i < nums.size(); i++) {
                path.push_back(i);
                hash_path[nums[i]] = i;
                this->backtrack(result, nums, path, hash_path);
                path.pop_back();
                hash_path[nums[i]] = -1;
            }

            for (int i = 0; i < result.size(); i++) {
                for (int j = 0; j < result[i].size(); j++) {
                    result[i][j] = nums[result[i][j]];
                }
            }

            // for (int i = 0; i < result.size(); i++) {
            //     for (int j = 0; j < result[i].size(); j++) {
            //         std::cout << result[i][j] << ", ";
            //     }
            //     std::cout << std::endl;
            // }

            return result;
        }
};