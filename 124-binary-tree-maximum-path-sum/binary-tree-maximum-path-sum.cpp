class Solution {
public:
    int bfs(TreeNode* root){
        if(!root) return 0;
        int l=max(0,bfs(root->left));
        int r=max(0,bfs(root->right));
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            int l=max(bfs(node->left),0);
            int r=max(bfs(node->right),0);
            ans=max(ans,l+r+node->val);
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return ans;
    }
};
//dfs
// class Solution {
// public:
//     int maxPathSum(TreeNode* root) {
//         int maxsum=INT_MIN;
//         maxPathDown(root,maxsum);
//         return maxsum;
//     }
//     int maxPathDown(TreeNode* node,int &maxsum){
//         if(node==NULL) return 0;
        
//         int l=max(0,maxPathDown(node->left,maxsum));
//         int r=max(0,maxPathDown(node->right,maxsum));

//         maxsum=max(maxsum,l+r+node->val);
        
//         return max(l,r)+node->val;
//     }
// };