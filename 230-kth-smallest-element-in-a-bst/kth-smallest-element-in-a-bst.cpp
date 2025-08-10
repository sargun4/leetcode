
class Solution {
public:
    int kthSmallest(TreeNode* root, int k){
        int ctr = countNodes(root->left);
        if (k <= ctr) {
            return kthSmallest(root->left, k);
        } else if (k > ctr + 1) {
            return kthSmallest(root->right, k-1-ctr); // 1 is counted as current node
        }
        return root->val;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};