/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode * root){
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max((1+left) , (1+right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int left = height(root->left);
        int right = height(root->right);
        if(right - left > 1 || right - left < -1){
            return false;
        }
       
        return(isBalanced(root->left) && isBalanced(root->right));
        
    }
};