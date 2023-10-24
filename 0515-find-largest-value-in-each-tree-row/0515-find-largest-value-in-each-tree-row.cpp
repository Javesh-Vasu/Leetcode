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
    vector<int> largestValues(TreeNode* root) {
        vector<int> largestElements;
        if ( root == nullptr ) return largestElements;
        queue<TreeNode*> treeRows;
        treeRows.push(root);
        
        while ( !treeRows.empty() ){
            int length = treeRows.size();
            int currMax = INT_MIN;
            while ( length-- ){
                TreeNode* node = treeRows.front();
                treeRows.pop();
                currMax = max( currMax , node->val);
                if ( node->left ) treeRows.push(node->left);
                if ( node->right ) treeRows.push(node->right);
            }
            largestElements.push_back(currMax);
        }
        return largestElements;
    }
   
};