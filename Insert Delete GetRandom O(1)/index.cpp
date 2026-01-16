#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

#include <cstdlib> /* 亂數相關函數 */
#include <ctime>   /* 時間相關函數 */

class RandomizedSet {
    private:
        std::unordered_set<int> num_list;
        std::vector<int> num_keys;
        int current_size;

        void remove_keys(int val) {
            for (int i = 0; i < this->num_keys.size(); i++) {
                if (this->num_keys[i] == val) {
                    std::swap(this->num_keys[i], this->num_keys.back());
                    this->num_keys.pop_back();
                    break;
                }
            }
        }
    public:
        RandomizedSet() {
            srand( time(NULL) );
            this->current_size = 0;
        }
        
        bool insert(int val) {
            if (this->num_list.find(val) != this->num_list.end()) {
                return false;
            }
            this->num_list.insert(val);
            this->current_size += 1;
            this->num_keys.push_back(val);
            return true;
        }

        bool remove(int val) {
            if (this->num_list.find(val) == this->num_list.end()) {
                return false;
            }
            this->num_list.erase(val);
            this->current_size -= 1;
            this->remove_keys(val);
            return true;
        }
        
        int getRandom() {
            int k = rand() % this->current_size;
            return this->num_keys[k];
        }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */