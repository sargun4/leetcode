class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(node) v.push_back(node->val);
            }
        }
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        for(int i=1;i<v.size();i++){
            ans=min(ans,abs(v[i]-v[i-1]));
        }
        return ans;
    }
};