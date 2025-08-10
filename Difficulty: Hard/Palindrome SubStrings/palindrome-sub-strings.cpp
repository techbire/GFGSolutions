class Solution {
  public:
    int helper(string &s, int i1, int i2){
        int start = i1-1, end = i2!=-1 ? i2+1 : i1+1;
        int cnt = i2 != -1  ? 1 : 0;
        while(start>=0 && end < s.size() && s[start] == s[end]){
            cnt++;
            start--;
            end++;
        }
        return cnt;
    }
    int countPS(string &s) {
        // code here
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            cnt += helper(s, i, -1);
            if(i+1<s.size() && s[i] == s[i+1]){
                cnt += helper(s, i, i+1);
            }
        }
        return cnt;
    }
};

