class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        int c=0;
        vector<vector<int>>ans;
         if(!root)
         return {};
         q.push(root); 
         while(!q.empty()){
             vector<int>lvl;
             int size=q.size();
             while(size--){
                 TreeNode* curr=q.front();
                 q.pop();
                 lvl.push_back(curr->val);
                 if(curr->left)
                    q.push(curr->left);
                 if(curr->right)
                    q.push(curr->right);
             }
             ans.push_back(lvl);
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};
// class Solution {
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         vector<vector<int>> res;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){            
//             vector<int> lvl;
//             int n=q.size();
//             for(int i=0;i<n;i++){
//                 TreeNode* node=q.front();
//                 q.pop();
//                 lvl.push_back(node->val);
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//             res.push_back(lvl);
//         }
//         vector<vector<int>> ans;
//         for(int i=res.size();i>0;i--){
//             ans.push_back(res[i]);
//         }
//         return ans;
//     }
// };

