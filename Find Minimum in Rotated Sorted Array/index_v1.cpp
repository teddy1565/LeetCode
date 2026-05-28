#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <array>
#include <set>
#include <numeric>
#include <unordered_set>
#include <charconv>

// 乘法交換律
// 好像跟coin或股票題目有點像
// [5, 7, -2,    5,   -33, 0, -98, 2, -3]
//  5. 35 2     10  11550 0 1  , 2
// -1 -1  35   -350 -165  0 -98, -196

/**
 *      a1      a2                 a3  
 * x    x1   x2 = (a2 * x1)
 * y    y1   y2 = (a2 * x1 * y1)
 * 
 */

 // 35 * -2 * 5 * -33 * 98 * -98

 // [5, 7,  -2,  5,      -33,    98,     -98,     0, -3]
 //  5  7   -2
//   5  35  -14
//.  5. 35


//    5


//max;35 35

//      [   5,  7,    -2,       5,      -33,    98,     -98,    0,  -3  ]
// 1        1   5     7        5       -33     98     -98
// 1        5   35    -14      -10      -165    -3234   -9604
// 1        5   35    -490    140     1650   533610 31059336

//      [2, 3, -2, 4]
// 1    2   6   1  4
// 1    1   1   -2 -2
class Solution {
    public:
        int findMin(std::vector<int>& nums) {
            
        }
};