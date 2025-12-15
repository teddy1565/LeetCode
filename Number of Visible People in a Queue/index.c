int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    (*returnSize) = heightsSize;
    int *answer = (int *) malloc(sizeof(int) * (*returnSize));
    memset(answer, 0, sizeof(int) * (*returnSize));

    int *height_stack = (int *) malloc(sizeof(int) * (*returnSize));
    int height_stack_index = 0;

    for (int i = heightsSize - 1; i >= 0; i--) {
        int n = 0;
        for (int j = height_stack_index - 1; j >= 0; j--) {
            if (height_stack[j] < heights[i]) {
                height_stack_index -= 1;
                n++;
            } else {
                n += 1;
                break;
            }
        }
        height_stack[height_stack_index++] = heights[i];
        answer[i] = n;
    }
    return answer;
}