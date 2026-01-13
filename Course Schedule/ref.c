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

bool canFinish(int n, int** pre, int ps, int* pc) {
    int col[2000] = {0};
    for (int i = 0; i < ps; i++) col[pre[i][1]]++;

    int** g = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) g[i] = malloc(sizeof(int) * col[i]);
    memset(col, 0, sizeof(col));

    for (int i = 0; i < ps; i++)
        g[pre[i][1]][col[pre[i][1]]++] = pre[i][0];

    int vis[2000] = {0}, path[2000] = {0};
    for (int i = 0; i < n; i++)
        if (!vis[i] && dfs(i, vis, path, g, col))
            return false;
    return true;
}