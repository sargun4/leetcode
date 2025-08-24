class info{
public:
    bool isBST;
    int min;
    int max;
    int sum;
};
class Solution {
public:
    info solve(TreeNode* root,int &ans){
        if(!root) return {true,INT32_MAX,INT32_MIN,0};
        info left=solve(root->left,ans);
        info right=solve(root->right,ans);
        info curr;
        //check if curr tree is a BST using the properties of BST
        curr.sum=left.sum+right.sum+root->val;
        curr.min=min(root->val,left.min);
        curr.max=max(root->val,right.max);
        curr.isBST= left.isBST && right.isBST && 
                    (root->val>left.max && root->val<right.min);
        if(curr.isBST){
            ans=max(ans,curr.sum);
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        int maxsum=0;
        solve(root,maxsum);
        return maxsum;               
    }
};