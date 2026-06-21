class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        vector<int> v;

        for (int x : a) v.push_back(x);
        for (int x : b) v.push_back(x);

        sort(v.begin(), v.end());

        return v[k - 1];
    }
};