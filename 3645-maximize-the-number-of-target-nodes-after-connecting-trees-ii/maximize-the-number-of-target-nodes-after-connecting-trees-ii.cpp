// class Solution {
// public:
//     vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
//         int n=edges1.size()+1;
//         int m=edges2.size()+1;
//         // unordered_map<int,vector<int>> adjA=getAdj(edges1);
//         // unordered_map<int,vector<int>> adjB=getAdj(edges2);
//         vector<vector<int>> adjA = getAdj(edges1, n);
//         vector<vector<int>> adjB = getAdj(edges2, m);
        
//         // A is fr Tree1
//         vector<int> markA(n,-1);
//         markA[0]=0; //mark 0th node of A as 0,since dfs we start frm here
//         int zeroMarkedCtrA=0;
//         int oneMarkedCtrA=0;
//         dfs(0,adjA,-1,markA,zeroMarkedCtrA,oneMarkedCtrA);//O(V+E)

//         // B for Tree2
//         vector<int> markB(m,-1);
//         markB[0]=0; //mark 0th node of B as 0,since dfs we start frm here
//         int zeroMarkedCtrB=0;
//         int oneMarkedCtrB=0;
//         dfs(0,adjB,-1,markB,zeroMarkedCtrB,oneMarkedCtrB);//O(V+E)

//         int maxFrmTree2=max(zeroMarkedCtrB,oneMarkedCtrB);

//         vector<int> res(n);
//         for (int i = 0; i < n; i++) {
//             res[i] = (markA[i] == 0 ? zeroMarkedCtrA : oneMarkedCtrA) + maxFrmTree2;
//         }
//         return res;
//     }
//     vector<vector<int>> getAdj(const vector<vector<int>>& edges, int n) {
//         vector<vector<int>> adj(n);
//         for (const auto& edge : edges) {
//             int u = edge[0];
//             int v = edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u); // Undirected graph
//         }
//         return adj;
//     }
//     // //O(V+E)
//     // // DFS to assign 0/1 marks alternately and count
//     // void dfs(int curr,vector<vector<int>> adj,int parent,vector<int>&mark,int &zeroMarkedCtr,int &oneMarkedCtr){
//     //     if(mark[curr]==0){
//     //         zeroMarkedCtr++;
//     //     }else{
//     //         oneMarkedCtr++;
//     //     }
//     //     for(auto& neigh:adj[curr]){
//     //         if(neigh!=parent && mark[neigh]==-1){
//     //             mark[neigh]=(mark[curr]==0) ? 1:0; //alternate marking
//     //             dfs(neigh,adj,curr,mark,zeroMarkedCtr,oneMarkedCtr);
//     //         }
//     //     }
//     // }
    
// };

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adjA = getAdj(edges1, n);
        vector<vector<int>> adjB = getAdj(edges2, m);

        // For Tree1
        vector<int> markA(n, -1);
        int zeroMarkedCtrA = 0, oneMarkedCtrA = 0;
        bfsColor(0, adjA, markA, zeroMarkedCtrA, oneMarkedCtrA);

        // For Tree2
        vector<int> markB(m, -1);
        int zeroMarkedCtrB = 0, oneMarkedCtrB = 0;
        bfsColor(0, adjB, markB, zeroMarkedCtrB, oneMarkedCtrB);

        int maxFromTree2 = max(zeroMarkedCtrB, oneMarkedCtrB);

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (markA[i] == 0) {
                res[i] = zeroMarkedCtrA + maxFromTree2;
            } else {
                res[i] = oneMarkedCtrA + maxFromTree2;
            }
        }
        return res;
    }
    // Build adjacency list
    vector<vector<int>> getAdj(const vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    // BFS for 2-coloring and counting
    void bfsColor(int start, const vector<vector<int>>& adj, vector<int>& mark,
                  int& zeroMarkedCtr, int& oneMarkedCtr) {
        queue<int> q;
        q.push(start);
        mark[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (mark[node] == 0) zeroMarkedCtr++;
            else oneMarkedCtr++;

            for (int neigh : adj[node]) {
                if (mark[neigh] == -1) {
                    mark[neigh] = 1 - mark[node];  // Alternate mark
                    q.push(neigh);
                }
            }
        }
    }
};
