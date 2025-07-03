class Solution {
public:
//build an undirected graph from the binary tree
    void makegraph(unordered_map<int,vector<int>> &adj,int parent,TreeNode* curr){
        if(curr==NULL) return;
        if(parent!=-1){//if curr node has a parent,connect it in graph
            adj[curr->val].push_back(parent);//store it in grpah
        }
        if(curr->left){//l child store
            adj[curr->val].push_back(curr->left->val);
        }if(curr->right){//r child
            adj[curr->val].push_back(curr->right->val);
        }
        makegraph(adj,curr->val,curr->left);
        makegraph(adj,curr->val,curr->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;//unord graph-adj list repr
 // Step 1- Convert the tree to graph
        makegraph(adj,-1,root);// -1=root has no parent
        queue<int> q;//q for bfs
        unordered_set<int> vis;//track infectd nodes
        q.push(start);//start frm infected ndoe
        vis.insert(start);//mark it 
        int min=0;//time
        while(!q.empty()){
            int n=q.size();//no of infected nodes at curr lvl-this sec
            while(n--){//goin over all nodes at curr lvl
                int curr=q.front();//curr infected node
                q.pop();
                for(int &neighbor:adj[curr]){//infect all unvis neigbors-child or parent
                    if(vis.find(neighbor)==vis.end()){
                        q.push(neighbor);//infect neigh
                        vis.insert(neighbor);//mark as vis
                    }
                }
            }
            min++;//1more sec/lvl passed
        }     
        return min-1;//since last lvl doesnt cause new infections,min-1
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