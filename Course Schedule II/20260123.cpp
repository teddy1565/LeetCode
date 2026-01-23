#include <iostream>
#include <vector>
#include <string>
#include <queue>

class Solution {
    public:
        std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
            std::vector<int> result;
            std::vector<std::vector<int>> adj_list(numCourses);
            std::vector<int> in_degree(numCourses, 0);

            
            for (int i = 0; i < prerequisites.size(); i++) {
                int course = prerequisites[i][0];
                int req = prerequisites[i][1];

                // initial if you want done a course, you need finish req_course first
                adj_list[req].push_back(course);
                
                // means this 'course' how many degree need done
                in_degree[course] += 1;
            }

            std::queue<int> course_queue;

            // if in_degree[i] == 0, means no pre_req_course need finish, so can push to queue
            for (int i = 0; i < numCourses; i++) {
                if (in_degree[i] == 0) {
                    course_queue.push(i);
                }
            }

            while (course_queue.size() > 0) {
                int course = course_queue.front();
                course_queue.pop();
                result.push_back(course);

                int adj_course_length = adj_list[course].size();

                for (int i = 0; i < adj_course_length; i++) {
                    int next_course = adj_list[course][i];
                    in_degree[next_course] -= 1;
                    if (in_degree[next_course] == 0) {
                        course_queue.push(next_course);
                    }
                }
            }

            return result.size() == numCourses ? result : std::vector<int>();
        }
};