#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    (*returnSize) = numCourses;
    int **adjacency_list = (int **) malloc(sizeof(int *) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        adjacency_list[i] = (int *) malloc(sizeof(int) * numCourses);
    }
    int *adjacency_list_index = (int *) malloc(sizeof(int) * numCourses);
    memset(adjacency_list_index, 0, sizeof(int) * numCourses);

    int *in_degree = (int *) malloc(sizeof(int) * numCourses);
    memset(in_degree, 0, sizeof(int) * numCourses);
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prerequisite_course = prerequisites[i][1];

        adjacency_list[prerequisite_course][adjacency_list_index[prerequisite_course]] = course;
        adjacency_list_index[prerequisite_course] += 1;

        in_degree[course] += 1;
    }

    int *course_queue = (int *) malloc(sizeof(int) * (numCourses * numCourses));
    int course_queue_index = 0;

    for (int course_id = 0; course_id < numCourses; course_id++) {
        if (in_degree[course_id] == 0) {
            course_queue[course_queue_index++] = course_id;
        }
    }

    int *course_order = (int *) malloc(sizeof(int) * numCourses);
    int course_order_index = 0;

    while (course_queue_index > 0) {
        int currentCourse = course_queue[0];
        for (int c = 1; c < course_queue_index; c++) {
            course_queue[c - 1] = course_queue[c];
        }
        course_queue_index -= 1;

        course_order[course_order_index++] = currentCourse;

        for (int i = 0; i < adjacency_list_index[currentCourse]; i++) {
            int dependent_course = adjacency_list[currentCourse][i];
            in_degree[dependent_course] -= 1;
            if (in_degree[dependent_course] == 0) {
                course_queue[course_queue_index++] = dependent_course;
            }
        }
    }

    if (course_order_index == numCourses) {
        return course_order;
    } else {
        (*returnSize) = 0;
        return NULL;
    }
}