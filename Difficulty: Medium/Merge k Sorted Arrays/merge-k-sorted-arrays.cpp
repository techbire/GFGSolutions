class Solution {
public:
    vector<int> mergeArrays(vector<vector<int>>& mat) {
        vector<int> res;

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                res.push_back(mat[i][j]);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};