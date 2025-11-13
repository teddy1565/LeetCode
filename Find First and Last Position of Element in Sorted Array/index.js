/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    const ans = [];
    ans.push(nums.findIndex((x) => x == target));
    nums.reverse();
    ans.push(nums.findIndex((x) => x == target));
    if (ans[1] != -1) {
        ans[1] = (nums.length-1) - ans[1];
    }
    return ans;
};