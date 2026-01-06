class Solution {
  public:
int maxSubarrayXOR(vector<int>& arr, int k) {
    int maxXor = 0;
    int xr = 0;

    for(int i = 0; i < k; i++){
        xr ^= arr[i];
    }
    maxXor = max(maxXor, xr);

    for(int i = k; i < arr.size(); i++){
        xr ^= arr[i];
        xr ^= arr[i - k];
        maxXor = max(maxXor, xr);
    }

    return maxXor;
}};