class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1) return 0;//Only one node, no steps needed
        string allvisit(n,'1');//bitmask when all nodes are visited (e.g., "1111")
        queue<pair<int,string>> q;//{node,vis_mask}
        string curr(n,'0');//string to hold curr bitmask state
        set<pair<int,string>> vis;//track vis states {node,mask}
        for(int i=0;i<n;i++){
            curr[i]='1';//mark node i as vis
            q.push({i,curr}); 
            vis.insert({i,curr});
            curr[i]='0';//reset for next node;
        }
        int step=0;//ctr of moves made
        int v;
        char tempchr;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                v=q.front().first;//curr node
                curr=q.front().second;//curr bitmask
                q.pop();
                for(int i=0;i<graph[v].size();i++){
                    int neigh = graph[v][i];
                    tempchr=curr[neigh];// Save curr bit
                    curr[neigh]='1';//mark neigh as vis
                    if(curr==allvisit) //all nodes vis
                        return step+1;
                    if(!vis.count({neigh,curr})){
                        q.push({neigh,curr});
                        vis.insert({neigh,curr});
                    }
                    curr[neigh]=tempchr;//restore state fr next itern
                }
            }
            step++;//nxt lvl bfs
        }
        return -1;//shd never reach here in a connected graph
    }
};

// class Solution {
// public:
//     typedef pair<int, int> p;
//     int shortestPathLength(vector<vector<int>>& graph) {
//         int n=graph.size();
//         if(n==1||n==0) return 0;
//         queue<p> q;
//         set<p> vis;
//         //Instead of set,can also use : vector<vector<bool>> visited(n, vector<bool>(finalState, false));
//         int allVisitedState = (1 << n) - 1; // if all nodes visited then
//         for(int i = 0; i < n; i++) {
//             int maskValue = (1 << i);            
//             q.push({i, maskValue});
//             vis.insert({i, maskValue});
//         }
//         int result = 0;
//         // Implementing BFS
//         while(!q.empty())  {
//             int N = q.size();
//             result++;
//             while(N--) {
//                 auto curr = q.front();
//                 q.pop();
//                 int currNode = curr.first;
//                 int currMask = curr.second;
//                 for(auto &adj: graph[currNode]) {
//                     int nextMask = currMask | (1 << adj);
//                     if(nextMask == allVisitedState)
//                         return result;
//                     if(vis.find({adj, nextMask}) == vis.end()) {
//                         vis.insert({adj, nextMask});
//                         q.push({adj, nextMask});                      
//                     }
//                 }  
//             }
//         }
//         return -1;
//     }
// };
