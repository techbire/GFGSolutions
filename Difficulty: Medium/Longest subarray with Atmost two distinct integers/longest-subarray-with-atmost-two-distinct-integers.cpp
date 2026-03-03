class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int l=0,r=0,n,count=0,ans=-1e9;
        unordered_map<int,int> mp;
        n=arr.size();
        while(r<n)
        {   
            if(mp[arr[r]]==0)count++;
            mp[arr[r]]++;
            while(count>2)
            {
                if(mp[arr[l]]==1)count--;
                mp[arr[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        
        return ans;
    }
};

