// //O(n)
// class Solution {
// public:
//     bool isBalanced(TreeNode *root){
//         return dfsHt(root)!=-1;
//     }
//     int dfsHt(TreeNode *root){
//         if(root==NULL) return 0;
        
//         int lht=dfsHt(root->left);
//         if(lht==-1) return -1;
//         int rht=dfsHt(root->right);
//         if(rht==-1) return -1;
        
//         if(abs(lht-rht)>1) return -1;
//         return max(lht,rht)+1;
//     }
// };
class Solution {
public:
    int ht(TreeNode *root){
        if(!root) return 0;
        return max(ht(root->left),ht(root->right))+1;
    }
    bool isBalanced(TreeNode *root){
        if(!root) return true;
        int left=ht(root->left);
        int right=ht(root->right);
        return abs(left-right) <=1 && isBalanced(root->left) && isBalanced(root->right);
    }
}; 