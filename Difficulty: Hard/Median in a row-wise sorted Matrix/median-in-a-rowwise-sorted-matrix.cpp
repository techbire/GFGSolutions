class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();       // number of rows
        int m = mat[0].size();    // number of columns
        
        vector<int> list;
        
      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                list.push_back(mat[i][j]);
            }
        }
        
    
        sort(list.begin(), list.end());
        
       
        int ans = list.size() / 2;
        
        return list[ans];
    }
};