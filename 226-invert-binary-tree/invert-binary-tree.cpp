// class Solution:
//     def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
//         if not root: #Base Case
//             return root
//         self.invertTree(root.left) #Call the left substree
//         self.invertTree(root.right)  #Call the right substree
//         # Swap the nodes
//         root.left, root.right = root.right, root.left
//         return root # Return the root

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        return root;
    }
};