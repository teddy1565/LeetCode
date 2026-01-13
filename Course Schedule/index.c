#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// 0 <= n <= 2000
int course_queue_pop(int *course_queue, int course_size) {
    int n = -1;
    if (course_size > 0) {
        n = course_queue[0];
        for (int i = 1; i < course_size; i++) {
            course_queue[i - 1] = course_queue[i];
        }
    }
    return n;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
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
        int require_course = prerequisites[i][1];

        adjacency_list[require_course][adjacency_list_index[require_course]] = course;
        adjacency_list_index[require_course] += 1;

        in_degree[course] += 1;
    }

    int *course_queue = (int *) malloc(sizeof(int) * (numCourses * numCourses));
    int course_queue_index = 0;

    // 尋找不存在pre_require的coruse 代表最上層
    for (int course_id = 0; course_id < numCourses; course_id++) {
        if (in_degree[course_id] == 0) {
            course_queue[course_queue_index++] = course_id;
        }
    }

    int *course_order = (int *) malloc(sizeof(int) * (numCourses));
    int course_order_index = 0;

    while (course_queue_index > 0) {
        int course = course_queue_pop(course_queue, course_queue_index);
        course_queue_index -= 1;
        course_order[course_order_index++] = course;

        for (int i = 0; i < adjacency_list_index[course]; i++) {
            int depends_coruse = adjacency_list[course][i];
            in_degree[depends_coruse] -= 1;
            if (in_degree[depends_coruse] == 0) {
                course_queue[course_queue_index++] = depends_coruse;
            }
        }
    }

    free(course_order);
    free(course_queue);
    free(in_degree);
    free(adjacency_list_index);
    for(int i = 0; i < numCourses; i++) {
        free(adjacency_list[i]);
    }
    free(adjacency_list);

    if (course_order_index == numCourses) {
        
        return true;
    } else {
        return false;

    }
}