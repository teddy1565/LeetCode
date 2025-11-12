/**
 * @param {number} n
 * @return {number}
 */
var hammingWeight = function(n) {
    // return n.toString(2).match(/1/g).length;
    return n.toString(2).replaceAll("0", "").length;
};