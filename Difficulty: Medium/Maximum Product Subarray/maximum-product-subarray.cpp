class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int prd = INT_MIN;
        int pre = 1, suf = 1;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            
            pre *= arr[i];
            suf *= arr[n - 1 - i];
            
            prd = max(prd, max(pre, suf));
        }
        return prd;
    }
};
