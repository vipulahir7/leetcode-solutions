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
    
    int f(TreeNode* root,int &ans){
        
        int left=0,right=0;
        if(root->left){
            left=f(root->left,ans);
        }
        if(root->right){
            right=f(root->right,ans);
        }
        int temp=max(max(left,right)+root->val,root->val);  //value to return parent
        int temp2=max(temp,left+right+root->val);   //current root wants to be main character of the film 
        ans=max(temp2,ans);
        return temp;
    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        f(root,ans);
        return ans;
    }
};