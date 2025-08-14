// 1.for any node, the longest univalue path through that node is:
// where:
// - left_path is the longest univalue path starting from the left child that continues with the node's value.
// - right_path is the longest univalue path starting from the right child that continues with the node's value.
// 2. The global max must be updated at every node based on the sum of its left and right same-value paths.
// 3. A DFS post-order traversal is ideal because:
// - We compute the longest univalue path from the bottom up.
// - We return the longest single branch path (either left or right) that can be extended by the parent
// ## Algorithm
// 1. Define a DFS function:
// - Base case: If the node is NULL, return 0.
// - Recursively call DFS on the left and right subtrees.
// - For each child:
//   - If the child value equals the current node value, extend the univalue path by 1.
//   - Otherwise, reset the path length for that child to 0.

// 2. At each node:
// - Compute left_path and right_path.
// - Update a global max_len as max(max_len, left_path + right_path) because the longest path through this node might be the sum of both directions.
// 3. Return the longest single path (max(left_path, right_path)) to the parent to allow further extension
class Solution {
public:
    int maxLen = 0;//track the longest univalue path
    // DFS returns the longest univalue path (in terms of edges) 
    // starting frm this node that can be extended by its parent
    int dfs(TreeNode* root) {
        if (!root) return 0;
        //rec for left and right subtrees
        int left = dfs(root->left);
        int right = dfs(root->right);
        //check if left child can be part of the univalue path
        int leftPath = 0;
        if (root->left && root->left->val == root->val) {
            leftPath=left+1; //extend left path
        }
        //check if right child can be part of the univalue path
        int rightPath=0;
        if (root->right && root->right->val == root->val) {
            rightPath=right+1;  // extend right path
        }
        //update global max (the path may pass through this node)
        maxLen = max(maxLen,leftPath + rightPath);        
        return max(leftPath,rightPath);//longest single dirn path
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return maxLen;
    }
};