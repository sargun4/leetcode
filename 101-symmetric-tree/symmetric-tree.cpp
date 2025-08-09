 
class Solution{
public:
    // check for symmetric tree
    bool isSymmetric(TreeNode* root){
        // Base case: null node is symmetric
        if(root==NULL)
            return true;
        // Recursive call: compare left subtree and right subtree
        return isSymmetricUtil(root->left, root->right);
    }
    bool isSymmetricUtil(TreeNode* t1, TreeNode* t2){
        // 1. Both null -> symmetric
        if(t1 == NULL && t2 == NULL)
            return true;
        // 2. One null, the other not -> not symmetric
        if(t1 == NULL || t2 == NULL)
            return false;
        // 3. Both not null, but different values -> not symmetric
        if(t1->val != t2->val)
            return false;
        // Recursive call: check for symmetric tree with left child and right child
        return isSymmetricUtil(t1->left, t2->right) && isSymmetricUtil(t1->right, t2->left);
    }
};