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
int ans;
    void height(TreeNode * root, int lvl){
        ans = max(ans, lvl);
        if(root->left) height(root->left, lvl+1);
        if(root->right) height(root->right, lvl+1);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        ans = 0;
        height(root, 1);
        return ans;
    }
};