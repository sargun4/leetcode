class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;//{node,child}
        q.push({root,0});
        ll maxwidth=0;
        while(!q.empty()){
            ll l=q.front().second;//lchild
            ll r=q.back().second;//rchild
            maxwidth=max(maxwidth,r-l+1);
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front().first;
                ll idx=q.front().second;
                q.pop();
                if(curr->left) q.push({curr->left,2*idx+1});//lchild
                if(curr->right) q.push({curr->right,2*idx+2});//rchild
            }
        }
        return maxwidth;
    }
};