#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            int s = newInterval[0], e= newInterval[1];
            vector<vector<int>> res;
            for (auto& p: intervals) {
                if (p[1] < s) {
                    res.push_back(p);
                } else {
                    if (p[0] > e ) {
                        res.push_back({s, e});
                        s = p[0];
                        e = p[1];
                    } else {
                        s = min(s, p[0]);
                        e = max(e, p[1]);
                    }
                }
            }
            res.push_back({s, e});
            return res;
        }
};