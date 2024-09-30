//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
Node* findMid(Node* head){
        Node* slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }
        return slow;
    }
    
    Node* reverseList(Node* head) {
    if (head == NULL) return NULL;
    Node* prev = NULL;Node* curr = head;Node* nexti = head->next;
    while (curr != NULL) {
        curr->next = prev;
        prev = curr;
        curr = nexti;
        if(nexti!=NULL)nexti=nexti->next;
    }
    
    return prev;
   }
  
    bool compareList(Node* head1, Node* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->data != head2->data) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
        
           if(head1 == NULL && head2 == NULL) {
        return true;
    }
    
    }

    bool isPalindrome(Node *head) {
        if(head==NULL || head->next==NULL) return true;
        Node* h=head;
        Node* mid = findMid(h);
        Node* h2=reverseList(mid);
        return compareList(head,h2);
    }
};


//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends