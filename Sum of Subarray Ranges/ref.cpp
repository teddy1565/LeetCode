#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    long long largest(vector<int>& nums){
        int n = nums.size();
        long long largestSum = 0;
        stack<int> st ;
        vector<int> pgr(n), ngr(n);
        for(int i=0; i < n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                int index = st.top();
                st.pop();
                ngr[index] = i - index;
            }
            st.push(i);
        }
        while(!st.empty()){
            int index = st.top();
            ngr[index] = n - index;
            st.pop();
        }
        for(int i=n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                int index = st.top();
                st.pop();
                pgr[index] = index - i;
            }
            st.push(i);
        }
        while(!st.empty()){
            int index = st.top();
            pgr[index] = index+1;
            st.pop();
        }
        for(int i=0; i < n; i++){
            largestSum += (long long) pgr[i]*ngr[i]*nums[i];
        }
        return largestSum;

    }
    long long smallest(vector<int>& nums){
        int n = nums.size();
        vector<int> psr(n,1), nsr(n,1);
        long long smallestSum = 0;
        stack<int> st;
        for(int i=0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                int index = st.top();
                st.pop();
                nsr[index] = i-index;
            }
            st.push(i);
        }
        while(!st.empty()){
            int index = st.top();
            nsr[index] = n - index;
            st.pop();
        }
        for(int i=n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                int index = st.top();
                st.pop();
                psr[index] = index - i;
            }
            st.push(i);
        }
        while(!st.empty()){
            int index = st.top();
            psr[index] = index + 1;
            st.pop();
        }
        for(int i=0; i < n; i++){
            smallestSum += (long long) nsr[i]*psr[i]*nums[i];
        }
        return smallestSum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return largest(nums) - smallest(nums);
    }
};