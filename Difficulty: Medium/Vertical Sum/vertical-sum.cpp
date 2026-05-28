/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  map<int,int>mp;
  public:
 void helper(Node*root, int dist){
      mp[dist] +=root -> data;
      if(root -> left )helper(root->left , dist -1);
      if(root -> right)helper(root-> right, dist +1);
      }
      
    vector<int> verticalSum(Node* root) {
        // code here
        helper(root , 0);
        vector<int> res ;
        for (auto i :mp){
            res.push_back(i.second);
        }
        return res;
    }
};