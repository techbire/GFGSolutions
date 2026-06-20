class Solution {
  public:
    int nthRoot(int n, int m) {
       int l=0;
       int r=m;
       while(l<=r){
           int mid=l+(r-l)/2;
           if(pow(mid,n)==m){
               return mid;
           }
           else if(pow(mid,n)<m){
               l=mid+1; 
           }
           else{
               r=mid-1;
           }
       }
       return -1;
    }
};