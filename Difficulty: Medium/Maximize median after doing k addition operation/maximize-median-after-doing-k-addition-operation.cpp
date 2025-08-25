class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int md = (n - 1) / 2;
        long sm = k;
        int sz = 1;
        int ans = k + arr[md];

        if (n % 2 == 0) {
            ans = (ans + arr[md + 1]) / 2;
            sm += arr[md++];
            sz++;
        }

        for (int i = md; i < n; i++) {
            sm += arr[i];
            int hf = static_cast<int>(sm / sz++);
            ans = min(ans, hf);
        }

        return ans;
    }
};