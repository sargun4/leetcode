class Solution {
public: 
    int sum=0;
    void helper(TreeNode* root){ //rev inorder
        if(root==NULL) return;
        helper(root->right);
        sum+=root->val;
        root->val=sum;
        helper(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        sum=0;
        helper(root);
        return root;
    }
};