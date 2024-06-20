class Solution {
public: 
    int sum=0;
    void helper(TreeNode* root){
        if(root==NULL) return;
        helper(root->right);
        root->val=root->val+sum;
        sum=root->val;
        helper(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        sum=0;
        helper(root);
        return root;
    }
};