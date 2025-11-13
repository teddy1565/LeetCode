int binarySearchLeft(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        if (nums[mid] == target) ans = mid;
    }
    return ans;
}

int binarySearchRight(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        if (nums[mid] == target) ans = mid;
    }
    return ans;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* ans = (int*)malloc(sizeof(int) * 2);
    ans[0] = binarySearchLeft(nums, numsSize, target);
    ans[1] = binarySearchRight(nums, numsSize, target);
    return ans;
}
