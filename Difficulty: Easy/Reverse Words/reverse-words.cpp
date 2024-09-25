//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.


 string reverseWords(string str) {
        char result[str.size()+1];
        int index = 0;
        int j=str.size() ;
        
        for(int i = str.size()-1;i>=0;i--)
        {   
            if(str[i]=='.' ||i ==0)
            {
                int start = i == 0?i:i+1;
                while(start<j)
                {  
                    result[index++] = str[start++];
                }
                if(i!=0)
                {
                    result[index++] = '.';
                }
                j = i;
            }
            
        }
        result[index]='\0';
       
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends