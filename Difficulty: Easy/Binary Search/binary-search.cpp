//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int low = 0, high = arr.size() - 1;

        // Jab tak low pointer high se chota ya barabar hai
        while (low <= high) {
            int mid = low + (high - low) / 2; // Overflow se bachne ke liye middle ka calculation
          
            // Agar mid pe element k ke barabar hai, toh index return kar do
            if (arr[mid] == k)
                return mid;
            // Agar mid ka element k se chhota hai, toh search right side me karte hai
            else if (arr[mid] < k)
                low = mid + 1;
            // Agar mid ka element k se bada hai, toh search left side me karte hai
            else
                high = mid - 1;
        }

        // Agar element nahi mila, toh -1 return karo
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int res = ob.binarysearch(arr, k);
        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends