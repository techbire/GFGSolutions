class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=0;
        }
        
        int ans = 1;
        
        
       for(int i=0;i<arr.size();i++){
           if(m[arr[i]]!=0)continue;
           int count = 1;
           
           int a = arr[i]-1;
           while(m.count(a)){
               if(m[a]!=0){count+=m[a];break;}
               count++;
               m[a]=1;
               a--;
           }
           
           m[arr[i]]=count;
           ans=max(ans,count);
           
       }
       
       return ans;
        
    }
};