class Solution {
public: 
    int sum=0;
    void solve(TreeNode* root){ //rev inorder- r root l
        if(root==NULL) return;
        solve(root->right);
        sum+=root->val;
        root->val=sum;
        solve(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        sum=0;
        solve(root);
        return root;
    }
};