class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=findHtleft(root);
        int rh=findHtright(root);
        //if left ht == right ht, tree is a perfect binary tree
        //perfect binary tree node count: (2^ht) - 1
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
//returns ht of leftmost path
    int findHtleft(TreeNode* node){
        int ht=0;
        while(node){
            ht++;
            node=node->left;
        }
        return ht;
    }
//returns ht of rightmost path
    int findHtright(TreeNode* node){
        int ht=0;
        while(node){
            ht++;
            node=node->right;
        }
        return ht;
    }
};