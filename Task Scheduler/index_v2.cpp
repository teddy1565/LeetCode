
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>

// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

// Return the minimum number of CPU intervals required to complete all tasks.

// Input: tasks = ["A","A","A","B","B","B"], n = 2

// Output: 8

// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

// After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.



// Example 2:

// Input: tasks = ["A","C","A","B","D","B"], n = 1

// Output: 6

// Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

// With a cooling interval of 1, you can repeat a task after just one other task.

// Example 3:

// Input: tasks = ["A","A","A", "B","B","B"], n = 3

// Output: 10

// Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

// There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

class Solution {
    public:
        int leastInterval(std::vector<char>& tasks, int n) {
            if (n == 1) {
                return tasks.size();
            }

            // recored {task} need run how many times
            std::unordered_map<char, int> tasks_map;

            // record {task} idle times
            std::unordered_map<char, int> executed_map;

            int tasks_size = tasks.size();

            // total need execute how many task counter
            int executed_count = tasks.size();

            // count runtime tick count
            int tick_count = 0;

            // init hash_map
            for (int i = 0; i < tasks_size; i++) {
                
                if (tasks_map.find(tasks[i]) == tasks_map.end()) {
                    tasks_map[tasks[i]] = 0;
                    executed_map[tasks[i]] = 0;
                }
                tasks_map[tasks[i]] += 1;
            }

            // get task_keys length
            int task_type_size = tasks_map.size();

            // get keys list
            std::vector<char> keys;
            keys.reserve(tasks_map.size());

            for(auto kv : tasks_map) {
                keys.push_back(kv.first);
            }

            // get keys size
            const int keys_size = keys.size();

            for (int i = 0; i < keys_size; i++) {
                std::cout << keys[i] << " | " << tasks_map[keys[i]] << ", " << executed_map[keys[i]] << std::endl;
            }
            std::cout << "-------------------------" << std::endl;

            // count idle times
            int idle_count = 0;
            while (executed_count > 0) {
                bool is_idle = true;

                for (int i = 0; i < keys_size; i++) {
                    if (tasks_map[keys[i]] > 0) {
                        if (executed_map[keys[i]] == 0) {
                            executed_map[keys[i]] = n;
                            is_idle = false;
                            break;
                        } else {
                            executed_map[keys[i]] -= 1;
                            if (executed_map[keys[i]] == 0) {
                                executed_count -= 1;
                                tasks_map[keys[i]] -= 1;
                            }
                        }
                    }
                }

                for (int i = 0; i < keys_size; i++) {
                    std::cout << keys[i] << " | " << tasks_map[keys[i]] << ", " << executed_map[keys[i]] << std::endl;
                }
                std::cout << "-------------------------" << std::endl;
                
                
                tick_count += 1;
                if (is_idle == false) {
                    idle_count += 1;
                }
            }

            for (int i = 0; i < keys_size; i++) {
                std::cout << keys[i] << " | " << tasks_map[keys[i]] << ", " << executed_map[keys[i]] << std::endl;
            }
            std::cout << "-------------------------" << std::endl;
            
            std::cout << "idle_count: " << idle_count << std::endl;
            
            return tick_count;
        }
};