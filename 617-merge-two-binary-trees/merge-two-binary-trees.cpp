 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root1,root2});
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            TreeNode* node1=curr.first;
            TreeNode* node2=curr.second;
            node1->val+=node2->val;//merge curr nodes
            // Handle left children
            if (node1->left && node2->left) {
                //both hv left children-merge em later
                q.push({node1->left, node2->left});
            } else if (!node1->left) {
                //1st tree has no left child-justattach frm 2nd tree
                node1->left = node2->left;
            }
            // Handle right children
            if (node1->right && node2->right) {
                q.push({node1->right, node2->right});
            } else if (!node1->right) {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};
// //dfs 
// class Solution {
// public:
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         if (root1 == NULL) return root2;
//         if (root2 == NULL) return root1;
//         TreeNode* node = new TreeNode(root1->val + root2->val);
//         node->left=mergeTrees(root1->left,root2->left);
//         node->right=mergeTrees(root1->right,root2->right);
//         return node;
//     }
// };