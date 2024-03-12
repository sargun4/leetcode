class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;

        set<int> values;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            values.insert(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (values.size() < 2) return -1;

        auto it = values.begin();
        ++it; // Move iterator to second element
        return *it;
    }
};
