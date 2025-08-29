class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        if(p.size()>s.size()){return "";}
        vector<int>fp(26,0),fs(26,0);
        for(auto x:p){fp[x-'a']++;}
        int res=INT_MAX,idx=-1,l=0,rt=0,req=p.size();
        for(int r=0;r<s.size();r++){
            char c=s[r];
            fs[c-'a']++;
            if(fp[c-'a']>0 and fs[c-'a']<=fp[c-'a']){
                rt++;
            }
            while(rt==req){
                if(r-l+1<res){
                    res=r-l+1;
                    idx=l;
                }
                char lc=s[l];
                fs[lc-'a']--;
                if(fp[lc-'a']>0 and fs[lc-'a']<fp[lc-'a']){
                    rt--;
                }
                l++;
            }
        }
        return (idx==-1)?"":s.substr(idx,res);
    }
};