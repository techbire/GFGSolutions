class Solution {
public:
    int maxChocolate(vector<vector<int>> &a) {
        int n=a.size(),m=a[0].size();
        vector<vector<int>> c(m,vector<int>(m,0)),nx(m,vector<int>(m,0));

        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                nx[i][j]=(i==j?a[n-1][i]:a[n-1][i]+a[n-1][j]);

        for(int r=n-2;r>=0;r--){
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    c[i][j]=-1e9;
                    for(int u=-1;u<=1;u++){
                        for(int v=-1;v<=1;v++){
                            int x=i+u,y=j+v;
                            if(x>=0&&x<m&&y>=0&&y<m){
                                int val=a[r][i]+(i==j?0:a[r][j])+nx[x][y];
                                c[i][j]=max(c[i][j],val);
                            }
                        }
                    }
                }
            }
            nx=c;
        }
        return nx[0][m-1];
    }
};