class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int top=0,b=n-1;
        while(top<b){
            if(mat[top][b]==1){
                top++;
            }
            else{
                b--;
            }
        }
        
        for(int i=0;i<n;i++){
            if(i==top) continue;
            if(mat[top][i] || !mat[i][top]){
                return -1;
            }
        }

        return top;
    }
};