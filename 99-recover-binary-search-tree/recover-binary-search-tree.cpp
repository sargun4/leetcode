class Solution {
private:
    void markTree(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
        if (!root) return;
        markTree(root->left, prev, first, end);
        if (prev) {
            if (root->val < prev->val) {
                if (!first) {
                    first = prev;
                }
                end = root;
            }
        }
        prev = root;
        markTree(root->right, prev, first, end);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *end = nullptr;
        markTree(root, prev, first, end);
        swap(first->val, end->val);
        return;
    }
};