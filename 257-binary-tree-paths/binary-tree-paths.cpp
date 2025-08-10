// //bfs
// class Solution {
// public:
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> ans;
//         queue<pair<TreeNode*,string>> q;
//         q.push({root,to_string(root->val)});
//         while(!q.empty()){
//             auto curr=q.front(); q.pop();
//             TreeNode* node=curr.first;
//             if(node){
//                 auto currpath=curr.second;
//                 if(!node->left && !node->right){//reached leaf
//                     ans.push_back(currpath);
//                 }
//                 if(node->left){
//                     q.push({node->left,currpath+"->"+to_string(node->left->val)});
//                 }
//                 if(node->right){
//                     q.push({node->right,currpath+"->"+to_string(node->right->val)});
//                 }
//             }
//         }
//         return ans;
//     }
// };

//dfs
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root,res,"");
        return res;
    }
    void dfs(TreeNode*root,vector<string>&res,string path){
        if(!root)return;
        path+=to_string(root->val);
        if(!root->left && !root->right){//leaf
            res.push_back(path);
        }else{//not yet reached leaf
            path+="->";
        }
        if(root->left) dfs(root->left,res,path);
        if(root->right) dfs(root->right,res,path);
    }
};