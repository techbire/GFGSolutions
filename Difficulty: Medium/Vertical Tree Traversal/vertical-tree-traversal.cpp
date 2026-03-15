/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<pair<Node*, int>> q;
        map<int, vector<int>> mp;

        q.push({root, 0});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            Node* node = p.first;
            int d = p.second;

            mp[d].push_back(node->data);

            if(node->left)
                q.push({node->left, d-1});

            if(node->right)
                q.push({node->right, d+1});
        }

        for(auto &it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};