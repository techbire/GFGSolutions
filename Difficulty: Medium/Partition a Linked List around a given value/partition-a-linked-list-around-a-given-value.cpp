//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
public:
    struct Node* partition(struct Node* head, int x) {
        Node* lessHead = new Node(0);
        Node* equalHead = new Node(0);
        Node* greaterHead = new Node(0);

        Node* less = lessHead;
        Node* equal = equalHead;
        Node* greater = greaterHead;

        Node* current = head;

        while (current != NULL) {
            if (current->data < x) {
                less->next = current;
                less = less->next;
            } else if (current->data == x) {
                equal->next = current;
                equal = equal->next;
            } else {
                greater->next = current;
                greater = greater->next;
            }
            current = current->next;
        }

        // Connect the three lists
        less->next = equalHead->next; // Connect less list to equal list
        equal->next = greaterHead->next; // Connect equal list to greater list
        greater->next = NULL; // Terminate the greater list

        return lessHead->next; // Return the head of the combined list
    }
};






//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        // Solution ob;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        head = ob.partition(head, x);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends