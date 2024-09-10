//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPrime(int N){
        // code here
        if (N <= 1) {
        return 0;
    }
    
    // Check for factors from 2 up to the square root of N
    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            return 0; // N is divisible by i, hence it is not prime
        }}
  
    
    return 1; // No factors found, hence N is prime
}
        

};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends