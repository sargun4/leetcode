class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return NULL;
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);
        if(root->right==NULL && root->left==NULL &&root->val==target){
            return NULL;
        }
        return root;
    }
}; 