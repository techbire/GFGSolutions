//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        // n=arr.size();
        // int count=n-2;
        // while(n>1){
        //     arr.push_front(arr[n]);
        //     arr.pop_back;
        //     arr.pop(arr[count]);
        //     count--;
            
        // }
        // return arr;
        
        // int k = 1;
        // int n = arr.size();
        
        // while (n > 1) {
        //     int lastElement = arr.back();
        //     arr.pop_back();
        //     arr.insert(arr.begin(), lastElement);

        //     int deleteIndex = n - k;
        //     arr.erase(arr.begin() + deleteIndex);

        //     n--;
        //     k++;
        // }

        // return arr[0];
        
        
      //tle
      
              deque<int>dq(arr.begin(),arr.end());
        int k=1;
        int n=arr.size();
        
            while(k<=dq.size()){
                int a=dq[dq.size()-1];
                dq.pop_back();
                dq.push_front(a);
                int b=dq.size()-k;
                dq.erase(dq.begin()+b);
                k++;
            }
                   
                   return dq[0];
        
   
        
        
    } 
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends