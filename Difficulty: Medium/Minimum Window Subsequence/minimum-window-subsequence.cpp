class Solution {
public:
    string minWindow(string s1, string s2) {
        string ans = s1 + "*";
        int n = s1.size(), m = s2.size();

        for(int i = 0; i < n; i++){
            int p1 = i, p2 = 0;

            while(p1 < n && p2 < m){
                if(s1[p1] == s2[p2]) p2++;
                p1++;
            }

            if(p2 == m){
                if(p1 - i < ans.size()){
                    ans = s1.substr(i, p1 - i);
                }
            }
        }

        if(ans == s1 + "*") return "";
        return ans;
    }
};
