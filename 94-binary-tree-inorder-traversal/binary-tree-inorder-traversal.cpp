// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*> st;
//         TreeNode* node=root;
//         vector<int> inorder;
//         while(true){
//             if(node!=NULL){
//                 st.push(node);
//                 node=node->left;
//             }else{
//                 if(st.empty()==true) break;
//                 node=st.top();
//                 st.pop();
//                 inorder.push_back(node->val);
//                 node=node->right;
//             }
//         }
//         return inorder;
//     }
// };

//rec
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
private:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};


// //morris
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         while (root) {
//             if (root -> left) {
//                 TreeNode* pre = root -> left;
//                 while (pre -> right && pre -> right != root) {
//                     pre = pre -> right;
//                 }
//                 if (!pre -> right) {
//                     pre -> right = root;
//                     root = root -> left;
//                 } else {
//                     pre -> right = NULL;
//                     nodes.push_back(root -> val);
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