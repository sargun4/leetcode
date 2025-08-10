class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            auto node=q.front(); q.pop();
            if(isLeaf(node->left)){
                sum+=node->left->val;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return sum;
    }
    bool isLeaf(TreeNode*node){
        if(!node) return false;
        if(!node->left && !node->right) return true;
        return false;
    }
};
////dfs
// class Solution {
// public:
//     int sumOfLeftLeaves(TreeNode* root) {
//         int res = 0;
//         //update res if root is not NULL
//         if (root != NULL){
//             //if left of root = NULL, then add val of left child
//             if (isLeaf(root->left))
//                 res += root->left->val;
//             else //else recur for left child of root
//                 res += sumOfLeftLeaves(root->left);
                
//             //recur for right child of root and update res
//             res += sumOfLeftLeaves(root->right);
//         }
//         return res;
//     }
//     bool isLeaf(TreeNode*node){
//         if (!node) return false;
//         if (!node->left && !node->right) return true;
//         return false;
//     }
// };