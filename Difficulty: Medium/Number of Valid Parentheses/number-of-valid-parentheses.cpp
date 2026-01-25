class Solution {
  public:
    map<pair<int,int>, int> mp;
    int solve(int op, int en)
    {
        if(en==0 || op==0)
        return 1;
        
        if(mp.find({op,en})!=mp.end())
        return mp[{op,en}];
        
        if(op==en)
        return mp[{op,en}] = solve(op-1, en);
        
        return mp[{op,en}] = (solve(op-1, en) + solve(op, en-1));
    }
    int findWays(int n) {
        if(n%2)
        return 0;
        return solve(n/2, n/2);
    }
};