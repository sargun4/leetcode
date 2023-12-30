/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution{
public:
    // check for symmetric tree
    bool isSymmetric(TreeNode* root){
        // Base case: null node is symmetric
        if(root ==NULL)
            return true;
        // Recursive call: compare left subtree and right subtree
        return isSymmetricUtil(root->left, root->right);
    }
    bool isSymmetricUtil(TreeNode* left, TreeNode* right){
        // 1. Both null -> symmetric
        if(left == NULL && right == NULL)
            return true;
        // 2. One null, the other not -> not symmetric
        if(left == NULL || right == NULL)
            return false;
        // 3. Both not null, but different values -> not symmetric
        if(left->val != right->val)
            return false;
        // Recursive call: check for symmetric tree with left child and right child
        return isSymmetricUtil(left->left, right->right) && isSymmetricUtil(left->right, right->left);
    }
};