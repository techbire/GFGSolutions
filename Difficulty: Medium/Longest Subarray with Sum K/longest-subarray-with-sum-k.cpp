class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<long long,int>prefixsum;
        int maxlen=0;
        long long sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==k){
                maxlen=max(maxlen,i+1);
            }
            if(prefixsum.find(sum)==prefixsum.end()){
            prefixsum[sum]=i;
            }
            
            int n=sum-k;
            if(prefixsum.find(n)!=prefixsum.end()){
                maxlen=max(maxlen,i-prefixsum[n]);
            }      
        }
        return maxlen;            
    }
};