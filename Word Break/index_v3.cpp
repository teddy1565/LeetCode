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


   /**
    *       apple pen
    * a
    * p
    * p
    * l
    * e
    * p
    * e
    * n
    * a
    * p
    * p
    * l      o
    * e       o
    * 
    */
class Solution {
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
            //std::unordered_map<std::string, int> word_count;

            int n = s.size();
            int m = wordDict.size();
            std::vector<char *> word_dict;
            std::vector<char *> word_index;

            for (int i = 0; i < m; i++) {
                //word_count[wordDict[i]] = 1;    // string index is n - 1
                wordDict[i].insert(0, "\0");
                word_dict.push_back(&wordDict[i].back());   // maybe use this?
                word_index.push_back(&wordDict[i].back());
            }

            std::vector<bool> dp(n + 1, false);
            std::vector<bool> select_str(m, true);

            dp[n] = true;
            
            for (int i = n - 1; i >= 0; i--) {
                for (int k = 0; k < m; k++) {
                    if (select_str[k] == false) {
                        continue;
                    }
                    char *ptr = word_dict[k];
                    if (*ptr == '\0') {
                        ptr = word_index[k];
                        select_str[k] = false;
                    }
                    if (*ptr == s[i] && select_str[k] == true) {
                        dp[i] = dp[i + 1];
                        ptr--;
                        word_dict[k] = ptr;
                    } else {
                        select_str[k] = false;
                    }
                }

                bool need_reset = true;
                for (int k = 0; k < m; k++) {
                    if (select_str[k] == true) {
                        need_reset = false;
                        break;
                    }
                }
                if (need_reset == true) {
                    select_str.assign(select_str.size(), true);
                }
            }

            return dp[0];
        }
};