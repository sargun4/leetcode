class Solution {
public:
    TreeNode* constructTree(int &preIdx,int &postIdx,vector<int>& preorder, vector<int>& postorder){
        TreeNode* root=new TreeNode(preorder[preIdx]);
        preIdx++;//mark node as created
        if(root->val!=postorder[postIdx]){//node has left child
            root->left=constructTree(preIdx,postIdx,preorder,postorder);
        }
        if(root->val!=postorder[postIdx]){//node has right child too
            root->right=constructTree(preIdx,postIdx,preorder,postorder);
        }
        postIdx++;//mark this node n its subtree as fully processed
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIdx=0; int postIdx=0;
        return constructTree(preIdx,postIdx,preorder,postorder);
    }
};