/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* flatten(Node* root) {
        vector<int> v;
        Node* t = root;

        while (t) {
            Node* b = t;
            while (b) {
                v.push_back(b->data);
                b = b->bottom;
            }
            t = t->next;
        }

        sort(v.begin(), v.end());

        Node* head = new Node(v[0]);
        Node* cur = head;

        for (int i = 1; i < v.size(); i++) {
            cur->bottom = new Node(v[i]);
            cur = cur->bottom;
        }

        return head;
    }
};
