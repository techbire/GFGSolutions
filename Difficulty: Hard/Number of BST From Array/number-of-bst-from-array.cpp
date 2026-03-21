#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBSTs(vector<int>& a) {
        int n = a.size();
        
        vector<int> b = a;
        sort(b.begin(), b.end());

        // catalan numbers
        vector<long long> c(n + 1);
        c[0] = c[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                c[i] += c[j] * c[i - j - 1];
            }
        }

        vector<int> res;

        for (int i = 0; i < n; i++) {
            int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            
            int l = idx;
            int r = n - idx - 1;

            res.push_back(c[l] * c[r]);
        }

        return res;
    }
};