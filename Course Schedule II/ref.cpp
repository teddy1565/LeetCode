#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list graph where edge from 'from' to 'to' means 
        // course 'from' is a prerequisite for course 'to'
        vector<vector<int>> adjacencyList(numCourses);
      
        // Track the number of prerequisites (incoming edges) for each course
        vector<int> inDegree(numCourses);
      
        // Process prerequisites to build graph and calculate in-degrees
        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
          
            // Add edge from prerequisite to course
            adjacencyList[prerequisiteCourse].push_back(course);
          
            // Increment in-degree for the course that has this prerequisite
            ++inDegree[course];
        }
      
        // Queue for BFS traversal - start with courses that have no prerequisites
        queue<int> courseQueue;
      
        // Find all courses with no prerequisites (in-degree = 0)
        for (int courseId = 0; courseId < numCourses; ++courseId) {
            if (inDegree[courseId] == 0) {
                courseQueue.push(courseId);
            }
        }
      
        // Result vector to store the course order
        vector<int> courseOrder;
      
        // Process courses using Kahn's algorithm (topological sort)
        while (!courseQueue.empty()) {
            // Take a course with no remaining prerequisites
            int currentCourse = courseQueue.front();
            courseQueue.pop();
          
            // Add to result as this course can be taken
            courseOrder.push_back(currentCourse);
          
            // Process all courses that depend on the current course
            for (int dependentCourse : adjacencyList[currentCourse]) {
                // Decrease in-degree as one prerequisite is completed
                if (--inDegree[dependentCourse] == 0) {
                    // If no more prerequisites remain, add to queue
                    courseQueue.push(dependentCourse);
                }
            }
        }
      
        // If all courses are processed, return the order; otherwise, cycle exists
        return courseOrder.size() == numCourses ? courseOrder : vector<int>();
    }
};