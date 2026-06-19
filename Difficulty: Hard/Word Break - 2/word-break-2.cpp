class Solution {
public:

    void solve(string s,
               unordered_set<string>& st,
               vector<string>& ans,
               string curr) {

        if (s.empty()) {
            curr.pop_back();      // remove last space
            ans.push_back(curr);
            return;
        }

        for (int i = 1; i <= s.size(); i++) {

            string word = s.substr(0, i);

            if (st.count(word)) {
                solve(s.substr(i), st, ans,
                      curr + word + " ");
            }
        }
    }

    vector<string> wordBreak(vector<string>& dict, string& s) {

        unordered_set<string> st(dict.begin(), dict.end());

        vector<string> ans;

        solve(s, st, ans, "");

        return ans;
    }
};