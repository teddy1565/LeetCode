#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MIN(a,b)(a>b?b:a)
//source
int minPathSum(int** grid, int gridSize, int* gridColSize){
    for (int i=1;i<gridSize;i++) {
        grid[i][0] += grid[i-1][0];
    }
    for (int i=1;i<gridColSize[0];i++) {
        grid[0][i] += grid[0][i-1];
    }
    for (int i=1;i<gridSize;i++) {
        for (int j=1;j<gridColSize[0];j++) {
            grid[i][j] += MIN(grid[i-1][j],grid[i][j-1]);
        }
    }
    return grid[gridSize-1][gridColSize[0]-1];
}
//testData
int **testDataGenerator() {
    int testData[3][3] = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    int row = 3;
    int col = 3;
    int **ptr = (int **) malloc(sizeof(int*)*row);
    for (int i=0;i<row;i++) {
        ptr[i] = (int *) malloc(sizeof(int)*col);
    }
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            ptr[i][j] = testData[i][j];
        }
    }
    return ptr;
}
int *testDataLeng(int col,int n) {
    int *ptr = (int *) malloc(sizeof(int)*col);
    for(int i=0;i<col;i++) {
        ptr[i] = n;
    }
    return ptr;
}

int main(void) {
    printf("%d\n",minPathSum(testDataGenerator(),3,testDataLeng(3,3)));
    return 0;
}