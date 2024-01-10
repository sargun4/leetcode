class Solution {
public:
    void makegraph(unordered_map<int,vector<int>> &adj,int parent,TreeNode* curr){
        if(curr==NULL) return;
        if(parent!=-1){
            adj[curr->val].push_back(parent);
        }
        if(curr->left){
            adj[curr->val].push_back(curr->left->val);
        }if(curr->right){
            adj[curr->val].push_back(curr->right->val);
        }
        makegraph(adj,curr->val,curr->left);
        makegraph(adj,curr->val,curr->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;
        makegraph(adj,-1,root);
        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);
        int min=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int curr=q.front();
                q.pop();
                for(int &neighbor:adj[curr]){
                    if(vis.find(neighbor)==vis.end()){
                        q.push(neighbor);
                        vis.insert(neighbor);
                    }
                }
            }
            min++;
        }     
        return min-1;
    }
};
//  //BFS
// class Solution {
// public:
//     unordered_map<int,vector<int>> v;  //adjacency list

//     //create undirected graph for every parent-child  -> BFS
//     void createGraph(TreeNode* root){
//         queue<pair<TreeNode*,int>> q;
//         q.push({root,-1});
//         while(q.size()){
//             auto [node,parent]= q.front(); q.pop();
//             if(parent!=-1){
//                 v[parent].push_back(node->val);
//                 v[node->val].push_back(parent);
//             }
//             if(node->left)  q.push({node->left,node->val});
//             if(node->right) q.push({node->right,node->val});
//         }   
//     }

//     int amountOfTime(TreeNode* root, int start) {
//         //create graph of given tree
//         createGraph(root);

//         //start bfs
//         queue<int> q;
//         unordered_map<int,bool> seen;
//         q.push(start);
//         seen[start]=true;
//         int time=0;
//         for(;q.size();time++){
//             int n= q.size();
//             while(n--){
//                 auto node= q.front();  q.pop();
//                 for(auto i:v[node]){
//                     if(!seen[i]){
//                         q.push(i);
//                         seen[i]=true;
//                     }
//                 }
//             }
//         }
//         return time-1;
//     }
// };
// // Time - O(n)
// // Space - O(n)