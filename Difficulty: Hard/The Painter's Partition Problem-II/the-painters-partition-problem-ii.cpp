class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low < high) {
            
            int mid = low + (high - low) / 2;
            
            int sum = 0, painters = 1;
            
            for(int x : arr) {
                if(sum + x <= mid) {
                    sum += x;
                } else {
                    painters++;
                    sum = x;
                }
            }
            
            if(painters <= k) 
                high = mid;
            else 
                low = mid + 1;
        }
        
        return low;
    }
};
