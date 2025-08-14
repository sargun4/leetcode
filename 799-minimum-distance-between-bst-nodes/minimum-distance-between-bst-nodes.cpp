class Solution {
public:
    int prev=-1;
    void inorder(TreeNode*root,int&ans){
        if(!root) return;
        inorder(root->left,ans);
        if(prev>=0){
            ans=min(ans,root->val - prev);
        }
        prev=root->val;
        inorder(root->right,ans);
    }
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        inorder(root,ans);
        return ans;
    }
};