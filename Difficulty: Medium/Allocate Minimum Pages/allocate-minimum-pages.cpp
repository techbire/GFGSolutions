class Solution {
  public:
    bool isPossible(vector<int> &arr, int k, int maxPages){
            int students = 1, pageSum = 0;
            for(int i=0;i<arr.size();i++){
                pageSum += arr[i];
                if(pageSum > maxPages){
                    students++;
                    pageSum = arr[i];
                }
                if(students > k)
                    return false;
            }
            return true;
        }
  
    int findPages(vector<int> &arr, int k) {
        if(k > arr.size()) return -1;
        
        int start = 0, end = 0, res = -1;
        for(int i=0;i<arr.size();i++){
            start = max(start, arr[i]);
            end += arr[i];
        }
        
        while(start <= end){
            int mid = start + (end-start)/2;
            if(isPossible(arr, k, mid)){
                res = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return res;
    }
};