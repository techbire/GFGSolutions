class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here
    sort(arr.begin(),arr.end());
    int check=1;
    for(int i=0;i<arr.size();i++){
        if(check<arr[i]){
            return check;
        }
        else{
            check+=arr[i];
        }}
        return check;
    }
};