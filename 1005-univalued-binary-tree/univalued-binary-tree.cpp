class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        bool l=root->left==NULL||root->left->val==root->val && isUnivalTree(root->left);
        bool r=root->right==NULL||root->right->val==root->val && isUnivalTree(root->right);

        return l && r;
    }
};