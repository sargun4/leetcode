class Solution {
public:
    void preorder(TreeNode* root,vector<int> &res){
        if(root==NULL) return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
};
// //iterative
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> preorder;
//         if(root==NULL) return preorder;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             root=st.top();
//             st.pop();
//             preorder.push_back(root->val);
//             if(root->right!=NULL){
//                 st.push(root->right);
//             }
//             if(root->left!=NULL){
//                 st.push(root->left);
//             }
//         }
//         return preorder;
//     }
// };
// Iterative solution using stack = O(n) time and O(n) space;
// Recursive solution = O(n) time and O(n) space (function call stack);
// Morris traversal = O(n) time and O(1) space.
// //morris traversal
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         while (root) {
//             if (root -> left) {
//                 TreeNode* pre = root -> left;
//                 while (pre -> right && pre -> right != root) {
//                     pre = pre -> right;
//                 }
//                 if (!pre -> right) {
//                     pre -> right = root;
//                     nodes.push_back(root -> val);
//                     root = root -> left;
//                 } else {
//                     pre -> right = NULL;
//                     root = root -> right;
//                 }
//             } else {
//                 nodes.push_back(root -> val);
//                 root = root -> right;
//             }
//         }
//         return nodes;
//     }
// };