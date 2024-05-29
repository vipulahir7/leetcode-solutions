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

    void find(TreeNode* root, vector<int> & ans, int level){
        if(ans.size()<=level){
            ans.push_back(root->val);
        }
        else{
            ans[level]=max(ans[level],root->val);
        }
        if(root->left) find(root->left,ans,level+1);
        if(root->right) find(root->right,ans,level+1);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        find(root,ans,0);
        return ans;
    }
};