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
        
    unordered_map<int,int> inIdx;
    
    TreeNode* solve(vector<int>& preorder,int start,int end,int inStart,int inEnd){
        
        if(start>end || inStart>inEnd) return NULL;
        
        int ele=preorder[start];
        int idx=inIdx[ele];
        
        TreeNode* root=new TreeNode(ele);
        
        root->left=solve(preorder,start+1,start+idx-inStart,inStart,idx-1);
        root->right=solve(preorder,start+idx-inStart+1,end,idx+1,inEnd);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            inIdx[inorder[i]]=i;
        }
        
        TreeNode* root = solve(preorder,0,n-1,0,n-1);
        return root;
        
    }
};