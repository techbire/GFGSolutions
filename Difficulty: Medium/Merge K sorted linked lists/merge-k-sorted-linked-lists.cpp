//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:


   Node* mergetwosortedlists(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1->data <= l2->data) {  
            l1->next = mergetwosortedlists(l1->next, l2); 
            return l1;
        } else {
            l2->next = mergetwosortedlists(l2->next, l1); 
            return l2;
        }
    }

    Node* partitionandmerge(int start, int end, vector<Node*>& arr) {
        if (start == end) {
            return arr[start];
        }
        int mid = start + (end - start) / 2;
        
        Node* L1 = partitionandmerge(start, mid, arr);  
        Node* L2 = partitionandmerge(mid + 1, end, arr); 
        
        return mergetwosortedlists(L1, L2);
    }

    Node* mergeKLists(vector<Node*>& arr) {
        int k = arr.size();  
        if (k == 0) return NULL;
        return partitionandmerge(0, k - 1, arr);
    }
};



//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<Node*> arr;
        vector<int> nums;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            nums.push_back(number);
        }
        int ind = 0;
        int N = nums.size();

        while (ind < N) {
            int n = nums[ind++];
            int x = nums[ind++];
            Node* head = new Node(x);
            Node* curr = head;
            n--;

            for (int i = 0; i < n; i++) {
                x = nums[ind++];
                Node* temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
            arr.push_back(head);
        }

        Solution obj;
        Node* res = obj.mergeKLists(arr);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends