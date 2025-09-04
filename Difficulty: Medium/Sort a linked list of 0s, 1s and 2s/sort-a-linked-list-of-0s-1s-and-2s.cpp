/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        Node* curr = head;
        Node* temp = new Node(-1);
        Node* new0 = temp;
        Node* temp1 = new Node(-1);
        Node* new1 = temp1;
        Node* temp2 = new Node(-1);
        Node* new2 = temp2;
        while(curr != NULL){
           if(curr->data == 0){
               new0->next = curr;
               new0 = curr;
           }
           else if(curr->data == 1){
               new1->next = curr;
               new1 = curr;
           }
           else if(curr->data == 2){
               new2->next = curr;
               new2 = curr;
           }
           curr = curr->next;
        }
        if(temp1->next != NULL){
            new0->next = temp1->next;
            new1->next = temp2->next;
            new2->next = NULL;
        }
        else{
            new0->next = temp2->next;
            new2->next = NULL;
        }
        head = temp->next;
        delete temp;
        return head;
    }
};