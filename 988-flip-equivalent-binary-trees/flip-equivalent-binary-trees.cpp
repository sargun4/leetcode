class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2 || root1->val != root2->val)
            return false;
        
        bool l1, r1, l2, r2;

        l1 = flipEquiv(root1->left, root2->left);
        r1 = flipEquiv(root1->right, root2->right);
        l2 = flipEquiv(root1->left, root2->right);
        r2 = flipEquiv(root1->right, root2->left);

        return ((l1 && r1) || (l2 && r2));
    }
};