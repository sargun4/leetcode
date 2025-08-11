// //bfs 
// class Solution {
// public:
//     vector<int> largestValues(TreeNode* root) {
//         if(!root) return {};
//         vector<int> maxarr;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             int n=q.size();
//             int maxval=INT_MIN;
//             for(int i=0;i<n;i++){
//                 TreeNode* node=q.front();
//                 q.pop();
//                 maxval=max(maxval,node->val);
//                 if(node->left){
//                     q.push(node->left);
//                 }
//                 if(node->right){
//                     q.push(node->right);
//                 }
//             }
//             maxarr.push_back(maxval);
//         }
//         return maxarr;
//     }
// };
 //dfs
class Solution {
public:
    vector<int> ans;
    vector<int> largestValues(TreeNode* root){
        if(!root) return {};
        dfs(root,0);
        return ans;
    }
    void dfs(TreeNode*node,int depth){
        if(node==NULL) return;
        if(depth==ans.size()){
            ans.push_back(node->val);
        }else{
            ans[depth]=max(ans[depth],node->val);
        }
        dfs(node->left,depth+1);
        dfs(node->right,depth+1);
    }
};


