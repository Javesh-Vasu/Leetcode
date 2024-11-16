/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> rightView;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            int size = nodes.size();
            rightView.push_back(nodes.front()->val);
            while(size){
                TreeNode* n = nodes.front();
                nodes.pop();
                if (n->right)
                nodes.push(n->right);
                if (n->left)
                nodes.push(n->left);
                size--;
            }
        }
        return rightView;
    }
};