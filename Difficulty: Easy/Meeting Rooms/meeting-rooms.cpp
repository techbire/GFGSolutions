class Solution {
  public:
    static bool canAttend(vector<vector<int>>& arr) {
      
        sort(arr.begin(), arr.end());

        for(int i = 1; i < arr.size(); i++) {
            if(arr[i][0] < arr[i-1][1]) {
                return false;   // overlap found
            }
        }
        return true;   // no overlap
    }
};