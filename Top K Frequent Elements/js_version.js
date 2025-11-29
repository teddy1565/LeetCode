/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = (nums, k) => {
    const list_map = new Map();
    for (const n of nums) {
        if (list_map.has(n)) {
            list_map.set(n, list_map.get(n) + 1);
        } else {
            list_map.set(n, 1);
        }
    }

    const result = [];

    for (const item of list_map) {
        result.push(item);
    }

    result.sort((a, b) => b[1] - a[1]);
    return result.slice(0, k).map((v) => v[0]);
};