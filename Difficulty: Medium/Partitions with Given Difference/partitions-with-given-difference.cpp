#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int sum = 0;
        for(int x: arr) sum += x;
        
        if(diff > sum || (sum + diff) % 2) return 0;
        
        int target = (sum + diff) / 2;
        
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        
        for(int x: arr){
            for(int j = target; j >= x; j--){
                dp[j] += dp[j-x];
            }
        }
        
        return dp[target];
    }
};