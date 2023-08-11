// class Solution { //O(n^2) brute force
// public:
//     int maxdiff;
//     void FindMaxDiffUtil(TreeNode* root,TreeNode* child){
//         if(root==NULL || child==NULL) return;
//         maxdiff=max(maxdiff,abs(root->val-child->val));
//         FindMaxDiffUtil(root,child->left);
//         FindMaxDiffUtil(root,child->right);
//     }
//     void FindMaxDiff(TreeNode*root){
//         if(root==NULL) return;
//         FindMaxDiffUtil(root,root->left);
//         FindMaxDiffUtil(root,root->right);

//         FindMaxDiff(root->left);
//         FindMaxDiff(root->right);
//     }
//     int maxAncestorDiff(TreeNode* root) {
//         maxdiff=-1;
//         FindMaxDiff(root);
//         return maxdiff;
//     }
// };

class Solution {
public:
    int FindMaxDiff(TreeNode* root,int minval,int maxval){
        if(root==NULL) return abs(minval-maxval);
        minval=min(minval,root->val);
        maxval=max(maxval,root->val);
        int l=FindMaxDiff(root->left,minval,maxval);
        int r=FindMaxDiff(root->right,minval,maxval);
        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root){
        return FindMaxDiff(root,root->val,root->val);
    }
};