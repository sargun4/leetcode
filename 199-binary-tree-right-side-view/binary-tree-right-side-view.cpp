class Solution {
public://bfs
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> res;
        //lvl order trav
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            TreeNode* node=NULL;
            while(n--){
                node=q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            res.push_back(node->val);
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         if(root==NULL){
//             return ans;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int nodesAtCurrLvl=q.size();
//             while(nodesAtCurrLvl){
//                 TreeNode* currnode=q.front();
//                 q.pop();
//                 if(nodesAtCurrLvl==1){
//                     ans.push_back(currnode->val);
//                 }
//                 if(currnode->left) q.push(currnode->left);
//                 if(currnode->right) q.push(currnode->right);
//                 nodesAtCurrLvl--;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// private:
//     void findRightSideView(TreeNode* node,vector<int> &ans){
//         if(node==NULL) return;
//         // {node,lvl}
//         queue<pair<TreeNode*,int>> q;
//         int currlvl=-1;
//         q.push({node,0});
//         while(!q.empty()){
//             auto elmnt=q.front();
//             q.pop();
//             node=elmnt.first;
//             int lvl=elmnt.second;
//             if(currlvl<lvl){
//                 ans.push_back(node->val);
//                 currlvl=lvl;
//             }
//             if(node->right!=nullptr) q.push({node->right,lvl+1});
//             if(node->left!=nullptr) q.push({node->left,lvl+1});
//         }
//     }
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         findRightSideView(root,ans);
//         return ans; 
//     }
// };


// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int>ans;
//         queue<TreeNode*> q;
//         if(root==NULL)
//         return ans;
//         q.push(root);
//         while(1){
//             int size=q.size();
//             if(size==0)
//             return ans;
//             vector<int> data;
//             while(size--){
//                 TreeNode* temp=q.front();
//                 q.pop();
//                 data.push_back(temp->val);
//                 if(temp->left!=NULL)
//                     q.push(temp->left);
//                 if(temp->right!=NULL)
//                     q.push(temp->right);
//             }
//             ans.push_back(data.back());
//         }
//     }
// };