class Solution {
public:
    int subarrayRanges(vector<int>& a) {
        int n = a.size();
        long long mx = 0, mn = 0;
        stack<int> st;

        // MAX contribution
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || a[st.top()] <= a[i])) {
                int j = st.top(); st.pop();
                int l = st.empty() ? j + 1 : j - st.top();
                int r = i - j;
                mx += 1LL * a[j] * l * r;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // MIN contribution
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || a[st.top()] >= a[i])) {
                int j = st.top(); st.pop();
                int l = st.empty() ? j + 1 : j - st.top();
                int r = i - j;
                mn += 1LL * a[j] * l * r;
            }
            st.push(i);
        }

        return mx - mn;
    }
};
