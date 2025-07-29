class Solution {
public:
    int maxsum = INT_MIN; // Global variable to store the final answer
    // Helper function that returns max root-to-leaf path sum
    int maxpath(Node* root) {
        // Base case
        if (!root) return 0;
        // If current node is a leaf, return its value
        if (!root->left && !root->right) {
            return root->data;
        }
        // Recurse on left and right subtrees
        int l = maxpath(root->left);
        int r = maxpath(root->right);
        // If both children exist, this node can be an ancestor of two leaves
        if (root->left && root->right) {
            int totalPathSum = l + r + root->data;
            maxsum = max(maxsum, totalPathSum); // Update the global max
            return max(l, r) + root->data;      // Return one path upward
        }
        // If only one child exists, return that path + root->data
        return root->left ? l + root->data : r + root->data;
    }
    int maxPathSum(Node* root) {
        if (!root) return 0;
        int result = maxpath(root);
        // If maxsum was never updated (e.g., tree has only one leaf)
        // Then return root-to-leaf path sum directly
        if (!root->left || !root->right) {
            return max(maxsum, result);
        }
        return maxsum;
    }
};