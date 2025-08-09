class Solution {
public:   
    bool isValidBSThelper(TreeNode* root,long minval,long maxval){
        if(root==NULL) return true;
        if(root->val<=minval || root->val>=maxval) return false;
        return isValidBSThelper(root->left,minval,root->val) 
        && isValidBSThelper(root->right,root->val,maxval);
    }
    bool isValidBST(TreeNode* root){
        return isValidBSThelper(root,LONG_MIN,LONG_MAX);
    }
};
 