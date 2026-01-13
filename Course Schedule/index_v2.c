#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int u, int* vis, int* path, int** g, int* col) {
    vis[u] = path[u] = 1;
    for (int i = 0; i < col[u]; i++) {
        int v = g[u][i];
        if (!vis[v] && dfs(v, vis, path, g, col)) return true;
        if (path[v]) return true;
    }
    path[u] = 0;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int col[2000] = { 0 };
    for (int i = 0; i < prerequisitesSize; i++) {
        col[prerequisites[i][1]] += 1;
    }

    int **adj = malloc(sizeof(int *) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        adj[i] = malloc(sizeof(int) * col[i]);
    }
    memset(col, 0, sizeof(col));
    for (int i = 0; i < prerequisitesSize; i++) {
        adj[prerequisites[i][1]][col[prerequisites[i][1]]++] = prerequisites[i][0];
    }
    int vis[2000] = { 0 };
    int path[2000] = { 0 };

    for (int i = 0; i < numCourses; i++) {
        if (!vis[i] && dfs(i, vis, path, adj, col)) {
            return false;
        }
    }
    return true;
}