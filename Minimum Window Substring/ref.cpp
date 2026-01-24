#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), m= t.size();
        vector<int> hash(256,0);
        int l=0,r=0;
        long long minlen=1e9;
        int sind=-1, ct=0;
        for(int i=0;i<m;i++){
            hash[t[i]]++;

        }
        while(r<s.size()){
            if(hash[s[r]]>0)ct++;
            hash[s[r]]--;
            while(ct==m){
                if(r-l+1<minlen)
               { minlen= r-l+1;
                sind = l;}
                hash[s[l]]++;
                if(hash[s[l]]>0)ct--; l++;
            }
            r++;
        }
        return sind == -1? "": s.substr(sind, minlen);
    }
};