// Each edge {x, y} means: Minion y admires minion x. directed edge from y → x.
// If x admires y, he also admires everyone whom y admires → implies transitive admiration.
// No two minions should have the same color if one admires the other.

// The longer the chain of admiration (depth of DAG), the more colors are needed.
// So, we need to find the length of the longest path in the DAG
// (i.e., the max level reached in BFS / DFS Topo sort).
// In a DAG, the minimum number of colors needed =
// length of longest path (starting from source node) = KAHN's
class Solution {
public:
    int minColour(int N, int M, vector<int> mat[]) {
        vector<int> adj[N+1];
        vector<int> indegree(N+1);
        for(int i=0;i<M;i++){
            adj[mat[i][0]].push_back(mat[i][1]);
            indegree[mat[i][1]]++;
        }
        queue<pair<int,int>> q;//{node, level};
        
        for(int i=1; i<=N; i++){
            if(indegree[i] == 0){
                q.push({i, 1});
            }
        }
        
        int ans = 0;
        
        while(!q.empty()){
            int level = q.front().second;
            int node = q.front().first;
            q.pop();
            
            ans = level;
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push({it, level+1});
                }
            }
        }
        return ans;
    }
};