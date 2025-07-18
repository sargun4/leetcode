//bfs
class Solution {
public:
    int sizeSubtree(TreeNode* root){
        if(!root) return 0;
        return 1 + sizeSubtree(root->left) + sizeSubtree(root->right);
    }
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
//Check if l and r subtree hts r equal and both subtrees r perfect.
    bool isPerfect(TreeNode* root){
        if(!root) return true;
        int lht=height(root->left);
        int rht=height(root->right);
        if(lht!=rht){
            return false;
        }
        return isPerfect(root->left) && isPerfect(root->right);
    }
    void bfs(TreeNode*root,vector<int>& sizes){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front(); q.pop();
            if(isPerfect(node)){
                int size=sizeSubtree(node);
                sizes.push_back(size);
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        //
        vector<int> sizes;
        if(!root) return -1;
        bfs(root,sizes);
        sort(sizes.rbegin(),sizes.rend());//sort in desc order-get largest elmnts first
        if(k>sizes.size()){
            return -1;
        }
        return sizes[k-1];
    }
};

// //dfs
// class Solution {
// public:
//     int sizeSubtree(TreeNode* root){
//         if(root==NULL) return 0;
//         int lsize=sizeSubtree(root->left);
//         int rsize=sizeSubtree(root->right);
//         return 1+lsize+rsize;
//     }
//     int height(TreeNode* root){
//         if(!root) return 0;
//         int lht=height(root->left);
//         int rht=height(root->right);
//         return 1+max(lht,rht);
//     }
// //Check if l and r subtree hts r equal and both subtrees r perfect.
//     bool isPerfect(TreeNode* root){
//         if(!root) return true;
//         int lht=height(root->left);
//         int rht=height(root->right);
//         if(lht!=rht){
//             return false;
//         }
//         return isPerfect(root->left) && isPerfect(root->right);
//     }
//     void dfs(TreeNode*root,vector<int>& sizes){
//         if(!root) return;
//         if(isPerfect(root)){//if that subtree is perfect
//             sizes.push_back(sizeSubtree(root));
//         }
//         dfs(root->left,sizes);
//         dfs(root->right,sizes);
//     }
//     int kthLargestPerfectSubtree(TreeNode* root, int k) {
//         //
//         vector<int> sizes;
//         dfs(root,sizes);
//         sort(sizes.rbegin(),sizes.rend());//sort in desc order-get largest elmnts first
//         if(k>sizes.size()){
//             return -1;
//         }
//         return sizes[k-1];
//     }
// };

// ## Problem
// Given a binary tree, find the size of the **k-th largest perfect subtree**.  
// A **perfect binary tree** is one where:
// - Every internal node has exactly **two children**.
// - All leaf nodes are at the same depth.

// ## Key Observations
// - We need to identify **perfect subtrees** and record their sizes.
// - A subtree rooted at `node` is perfect if:
//   1. Its **left subtree** and **right subtree** are perfect.
//   2. Heights of left and right subtrees are **equal**.

// ## Steps:
// 1. Perform **DFS traversal**:
//    - Return a tuple: `(isPerfect, height, size)`.
//    - If `node == NULL` → `(true, 0, 0)`.
// 2. At each node:
//    - Check if left and right are perfect and heights match.
//    - If perfect → compute size = `left.size + right.size + 1` and store it.
// 3. Sort all collected sizes in **descending order**.
// 4. Return the `k-th` largest size or `-1` if not enough perfect subtrees exist.
// ## Complexity
// - **Time:** O(N) (DFS + sorting O(M log M), where M ≤ N).
// - **Space:** O(N) (for storing sizes and recursion stack).
 
// ```cpp
// class Solution {
// public:
//     struct Info {
//         bool isPerfect;
//         int height;
//         int size;
//     };

//     vector<int> sizes; // Stores sizes of all perfect subtrees
//     Info dfs(TreeNode* root) {
//         if (!root) return {true, 0, 0};
//         Info left = dfs(root->left);
//         Info right = dfs(root->right);
//         if (left.isPerfect && right.isPerfect && left.height == right.height) {
//             int subtreeSize = left.size + right.size + 1;
//             sizes.push_back(subtreeSize);
//             return {true, left.height + 1, subtreeSize};
//         }
//         return {false, max(left.height, right.height) + 1, left.size + right.size + 1};
//     }
//     int kthLargestPerfectSubtree(TreeNode* root, int k) {
//         sizes.clear();
//         dfs(root);
//         if ((int)sizes.size() < k) return -1;
//         sort(sizes.rbegin(), sizes.rend()); // Sort in descending order
//         return sizes[k - 1];
//     }
// };