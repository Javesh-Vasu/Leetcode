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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if ( root == nullptr ) return {};
        map<int,vector<int>> levelWise;
        queue<pair<TreeNode*,int>> levelOrder;
        levelOrder.push({root,1});
        while(!levelOrder.empty()){
            auto ele = levelOrder.front();
            levelOrder.pop();
            TreeNode* node = ele.first;
            int level = ele.second;
            if(node){
                levelWise[level].push_back(node->val);
                if ( node->left)
                    levelOrder.push({node->left,level+1});
                if ( node->right)
                    levelOrder.push({node->right,level+1});
            }
            
        }
        vector<vector<int>> ans;
        for ( const auto& x : levelWise){
            ans.push_back(x.second);
        }
        return ans;
    }
};