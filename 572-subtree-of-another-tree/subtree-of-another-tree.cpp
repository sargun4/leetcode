// #O(tree*subtree)
 
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root||!subRoot) { //if either is null not both atsame time
            return false;
        }
        if(sameTree(root, subRoot)) {
            return true;
        }
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) { //if both are null
            return true;
        }
        if (root && subRoot && root->val == subRoot->val) {
            return (sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right));
        }
        return false;
    }
};
