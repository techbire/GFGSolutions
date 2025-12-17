class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(), arr.end());
        int first=arr[0][0], second=arr[0][1];
        for(int i=1; i<arr.size(); i++){
            if(arr[i][0]>second){
                ans.push_back({first, second});
                first=arr[i][0]; second=arr[i][1];
            }
            else{
                second=max(second, arr[i][1]);
            }
        }
        ans.push_back({first, second});
        return ans;
    }
};