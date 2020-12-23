

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result = (int*)malloc(sizeof(int)*(*returnSize));
    for(int i=0;i<numsSize;i++){
        int found=0;
        int n1 = nums[i];
        int another = target-n1;
        for(int j=0;j<numsSize;j++){
            if(j==i)continue;
            if(nums[j]==another){
                result[0]=i;
                result[1]=j;
                found=1;
                break;
            }
        }
        if(found==1)break;
    }
    return result;
}