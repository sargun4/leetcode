class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;//{node,sum}
        q.push({root,root->val});
        int totalsum=0;
        int sum; TreeNode* node;
        while(!q.empty()){
            auto curr=q.front(); q.pop();
            node=curr.first;
            sum=curr.second;
            if(!node->left && !node->right){//leaf node
                totalsum+=sum;
            }else{
                if(node->left){
                    q.push({node->left,sum*10+node->left->val});
                }if(node->right){
                    q.push({node->right,sum*10+node->right->val});
                }
            }
        }
        return totalsum;
    }
};
// class Solution {
// public:
//     int solve(TreeNode* root,int curr){
//         if(!root) return 0;
//         curr=curr*10+root->val;
//         if(root->left==NULL && root->right==NULL){//leaf node
//             return curr;
//         }
//         int l=solve(root->left,curr);
//         int r=solve(root->right,curr);
//         return l+r;
//     }
//     int sumNumbers(TreeNode* root) {
//         return solve(root,0);
//     }
// };