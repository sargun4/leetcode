//bfs-O(N × h) in worst case
// since N nodes visited once
// String concatenation takes up to O(h) where h is tree height
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*,string>>q;//(node, stringFrmThisNodeToLeaf)
//convert root->val (0–25) to corresponding char ('a' + val)
        string ch=string(1,char(root->val+'a'));
        q.push({root,ch});
        string ans="";//lexciogrphiclly smallest path
        while(!q.empty()){
            auto[node,curr]=q.front();
            q.pop();
            if(!node->left && !node->right){//leaf
                if(ans=="" ||ans>curr){//update ans
                    ans=curr;
                }
            }
//need the string from leaf to root, so prepend the curr node's char to the running string
            if(node->left){
                q.push({node->left,char(node->left->val+'a')+curr});
            }
            if(node->right){
                q.push({node->right,char(node->right->val+'a')+curr});
            }
        }
        return ans;
    }
};
// //dfs
// class Solution {
// public:
//     string ans="";
//     void dfs(TreeNode *root,string curr){
//         if(!root) return;
//         curr=char(root->val+'a')+curr;
//         if(!root->left && !root->right){
//             if(ans==""||ans>curr){
//                 ans=curr;
//             }
//             return;
//         }
//         dfs(root->left,curr);
//         dfs(root->right,curr);
//     }
//     string smallestFromLeaf(TreeNode* root) {
//         dfs(root,"");
//         return ans;
//     }
// };