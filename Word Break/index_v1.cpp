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

// catsdog.    cat, cats, send, dog

/**
 *          c a t s e n d o g
 * cat      o o o x x x x
 * cats     o o o o x x x
 * send.    x x x o o o o
 * dog      x x x x x x o
 * 
 */

 /**
  *     cat cats send dog
  * c.  o   o
  * a    o   o
  * t     o   o
  * s          o o
  * d                 o
  * o                  o
  * g                   o
  * 
  */

  /**
   *    god dnes stac tac
   * g  o
   * o   o
   * d    o
   * s           o  
   * t            o   o
   * a             o   o
   * c              o   o
   */

  /**
   *        cat cats send dog
   * c      o   o
   * a       o   o
   * t        o   o
   * s             o o
   * e                o
   * n                 o
   * d                  o o
   * o                     o
   * g                      o
   * 
   */
class Solution {
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
            //std::unordered_map<std::string, int> word_count;

            int n = s.size();
            int m = wordDict.size();
            std::vector<char *> word_dict;

            for (int i = 0; i < m; i++) {
                //word_count[wordDict[i]] = 1;    // string index is n - 1
                wordDict[i].insert(0, "\0");
                word_dict.push_back(&wordDict[i].back());   // maybe use this?
            }

            std::vector<bool> dp(n, false);
            
            for (int i = n - 1; i >= 0; i--) {
                bool can_match = false;
                for (int k = 0; k < m; k++) {
                    char *ptr = word_dict[k];
                    if (*ptr == '\0') {
                        continue;
                    }
                    if (*ptr == s[i]) {
                        can_match = true;
                        ptr--;
                        word_dict[k] = ptr;
                    }
                }
                dp[i] = can_match;
            }

            return dp[0];
        }
};