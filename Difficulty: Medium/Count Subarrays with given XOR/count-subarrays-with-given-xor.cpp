class Solution {
  public:
        // code here
    int subarrayXor(vector<int>& arr, int k) {
    unordered_map<int, int> mp;

    mp[0] = 1;
    int xr = 0;
    int count = 0;

    for (int j = 0; j < arr.size(); j++) {
        xr ^= arr[j];

        if (mp.find(xr ^ k) != mp.end()) {
            count += mp[xr ^ k];
        }

        mp[xr]++;
    }

    return count;}
    
};