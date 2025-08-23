// class Solution {//dfs
// public:
// int ans;
//     void solve(TreeNode* root,bool flag,int ctr){
//         if(!root) return;
//         ans=max(ans,ctr);
//         if(flag){
//              solve(root->left,!flag,ctr+1);
//              solve(root->right,1,1);
//         }else{
//               solve(root->right,!flag,ctr+1);
//              solve(root->left,0,1);
//         }
//     }
//     int longestZigZag(TreeNode* root) {
//         ans=0;
//         solve(root->left,0,1);
//         solve(root->right,1,1);
//         return ans;
//     }
// };

//bfs
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,pair<int,int>>>q; //{node, {ans, dir}}
        q.push({root,{0, 0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node = p.first;
            int ctr = p.second.first;//len of longest zigzag path till this node
            int dir = p.second.second;//dirn = 1 or -1
            ans=max(ans, ctr);
            if(node->left){
                if(dir==1) //if right-to-left, 
                    q.push({node->left, {ctr+1, -1}});//enqueue l child w (ctr+1) & dirn -1
                else
                    q.push({node->left, {1, -1}});//enqueue left child w a path len of 1 & dirn -1
            }
            if(node->right){
                if(dir==-1)//left-to-right,
                    q.push({node->right, {ctr+1, 1}});//enqueue right child w (ctr+1) & dirn 1
                else
                    q.push({node->right, {1, 1}});//enqueue right child w a path len of 1 & dirn 1
            }
        }
        return ans;
    }
};