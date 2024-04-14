/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isLeaf(struct TreeNode *node){
  if (node == NULL)
    return false;
  if (node->left == NULL && node->right == NULL)
    return true;
  return false;
}

int sumOfLeftLeaves(struct TreeNode *root){
  int res = 0;
 
  // Update result if root is not NULL
  if (root != NULL){
    // If left of root is NULL, then add val of
    // left child
    if (isLeaf(root->left))
      res += root->left->val;
    else // Else recur for left child of root
      res += sumOfLeftLeaves(root->left);
 
    // Recur for right child of root and update res
    res += sumOfLeftLeaves(root->right);
  }
  return res;
}