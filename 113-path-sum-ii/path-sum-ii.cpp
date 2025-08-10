// Track Parents:
// Use a BFS traversal to build a parent map that stores each node's parent for easy backtracking from leaf to root.

// Find Target Leaf Nodes:
// Run another BFS, keeping a running sum for each node. If a node is a leaf and the sum of the path from root to that node equals targetSum, add it to a list of valid leaf nodes.

// Backtrack to Build Paths:
// For each valid leaf, backtrack using the parent map to collect the full path up to the root. Reverse the path to get it in root-to-leaf order.

//bfs
class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front(); q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    //bfs to get all leaf nodes whose root to path sum=target
    void leaf(TreeNode* root,int target,vector<TreeNode*>&l){
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        while(!q.empty()){
            auto [node,sum]=q.front(); q.pop();
            if(!node->left && !node->right){//leaf node
                if(sum==target){
                    l.push_back(node);
                }
            } 
            if(node->left){
                q.push({node->left,sum+node->left->val});
            }
            if(node->right){
                q.push({node->right,sum+node->right->val});
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;//empty tree
        unordered_map<TreeNode*,TreeNode*>parents;//{child:parent}
        vector<TreeNode*> validLeaves;//leaves with path sum=target
        markParents(root,parents);//mark parents in map
        leaf(root,targetSum,validLeaves);
        //backtrack each leaf to root using parents map
        for(auto leaf:validLeaves){
            vector<int> path;
            TreeNode*curr=leaf;
            while(curr){
                path.push_back(curr->val);
                curr=parents[curr];//go frm curr node to parent in path upwards
            }
            reverse(path.begin(),path.end());//root to leaf
            ans.push_back(path);
        }
        return ans;
    }
};
//dfs
// class Solution {
// public:
//     vector<vector<int>> res;
//     void fill(TreeNode* root,int sum,vector<int> temp,int &targetSum){
//         if(!root) return;
//         sum+=root->val;
//         temp.push_back(root->val);
//         //if leaf node
//         if(root->left==NULL && root->right==NULL){
//             if(sum==targetSum){
//                 res.push_back(temp);
//             }
//             return;
//         }
//         fill(root->left,sum,temp,targetSum);
//         fill(root->right,sum,temp,targetSum);
//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         int sum=0;
//         vector<int> temp;
//         fill(root,sum,temp,targetSum);
//         return res;
//     }
// };