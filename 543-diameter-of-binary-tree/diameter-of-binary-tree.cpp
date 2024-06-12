 
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diam=0;
        ht(root,diam);
        return diam;
    }
private:
    int ht(TreeNode *node,int &diam){
        if(!node)
            return 0;
        int lht=ht(node->left,diam);
        int rht=ht(node->right,diam);
        diam=max(diam,lht+rht);
        return 1+max(lht,rht);
    }
};