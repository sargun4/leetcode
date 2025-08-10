//bfs
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            TreeNode* temp=node->left;
            node->left=node->right;
            node->right=temp;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return root;
    }
};
// //dfs
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(!root){
//             return root;
//         }
//         invertTree(root->left);
//         invertTree(root->right);
//         swap(root->left,root->right);
//         return root;
//     }
// };