
class Solution {
public:
    int maxAncestorDiff(TreeNode* root){
        queue<pair<TreeNode*,pair<int,int>>> q; //{node:{max,min}};
        q.push({root,{root->val,root->val}});
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto curr=q.front(); q.pop();
                TreeNode* node=curr.first;
                int mx=curr.second.first;
                int mi=curr.second.second;
                //at each lvl,compare each node val
                if(node->left){
                    int maxval=max(mx,node->left->val);
                    int minval=min(mi,node->left->val);
                    q.push({node->left,{maxval,minval}});
                    ans=max(ans,maxval-minval);
                }
                if(node->right){
                    int maxval=max(mx,node->right->val);
                    int minval=min(mi,node->right->val);
                    q.push({node->right,{maxval,minval}});
                    ans=max(ans,maxval-minval);
                }
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     int FindMaxDiff(TreeNode* root,int minval,int maxval){
//         if(root==NULL) return abs(minval-maxval);
//         minval=min(minval,root->val);
//         maxval=max(maxval,root->val);
//         int l=FindMaxDiff(root->left,minval,maxval);
//         int r=FindMaxDiff(root->right,minval,maxval);
//         return max(l,r);
//     }
//     int maxAncestorDiff(TreeNode* root){
//         return FindMaxDiff(root,root->val,root->val);
//     }
// };