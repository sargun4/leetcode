class Solution {
public:
    string tree2str(TreeNode* root) {
         if(root==NULL){
            return "";
        }
        string res=to_string(root->val);
        string left=tree2str(root->left);
        string right=tree2str(root->right);  
        if(root->left==NULL && root->right==NULL){
            return res;
        }
        if(root->left==NULL){
            return res+"()"+"("+right+")";
        }
        if(root->right==NULL){
            return res+"("+left+")";
        }
        return res+"("+left+")"+"("+right+")";
    } 
 
};