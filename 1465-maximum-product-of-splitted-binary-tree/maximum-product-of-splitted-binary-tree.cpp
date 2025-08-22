#define ll long long

class Solution {
public:
    int mod=(int)1e9+7;
    ll sum=0, res=INT_MIN;
    ll solve(TreeNode* root){
        if(!root) return 0;
        ll left=solve(root->left);
        ll right=solve(root->right);
        ll currsum=left+right+root->val;
        ll maxprod=(sum-currsum)*currsum;
        res=max(maxprod,res);
        return currsum;
    }
    int maxProduct(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            sum+=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        solve(root);
        return res%mod;
    }
};