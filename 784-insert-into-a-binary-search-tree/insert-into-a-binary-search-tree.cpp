class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        if(root->val<val){//go right
            root->right=insertIntoBST(root->right,val);
        }else if(root->val>val){//go left
            root->left=insertIntoBST(root->left,val);
        }
        return root;
    }
};