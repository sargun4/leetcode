// class Solution {
// public:
//     void helper(TreeNode*root, int low, int high) {
//         if(root==NULL) return;
//         while(root->left!=NULL){
//             if(root->left->val<low) root->left=root->left->right;
//             else if(root->left->val>high) root->left=root->left->left;
//             else break;
//         }
//         while(root->right!=NULL){
//             if(root->right->val>high) root->right=root->right->left;
//             else if(root->right->val<low) root->right=root->right->right;
//             else break;
//         }
//         helper(root->left,low,high);
//         helper(root->right,low,high);
//     }
//     TreeNode*trimBST(TreeNode*root, int low, int high) {
//         TreeNode* parent=new TreeNode(INT_MAX);
//         parent->left=root;
//         helper(parent,low,high);
//         return parent->left;
//     }
// };
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;
        //if the curr node's value is less than low,
        //then we need to trim its left subtree and return the trimmed right subtree
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        //if the curr node's value is greater than high,
        //then we need to trim its right subtree and return the trimmed left subtree
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        //if the curr node's val is within the range [low, high],
         // then we need to recursively trim both its left and right subtrees
        root->left=trimBST(root->left, low, high);
        root->right=trimBST(root->right, low, high);
        // Return the updated root after the trimming process
        return root;
    }
};
