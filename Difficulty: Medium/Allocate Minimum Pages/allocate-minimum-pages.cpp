class Solution {
public:
    int findPages(vector<int>& a, int k) {
        if (a.size() < k) return -1;

        int l = *max_element(a.begin(), a.end());
        int r = accumulate(a.begin(), a.end(), 0);

        while (l < r) {
            int m = l + (r - l) / 2, s = 0, c = 1;

            for (int x : a) {
                if (s + x > m) c++, s = x;
                else s += x;
            }

            c <= k ? r = m : l = m + 1;
        }
        return l;
    }
};