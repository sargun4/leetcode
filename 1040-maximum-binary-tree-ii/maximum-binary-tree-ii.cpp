class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root==NULL||val > root->val) {
            auto n=new TreeNode(val);
            n->left=root;
            return n;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};