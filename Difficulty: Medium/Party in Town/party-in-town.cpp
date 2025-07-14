class Solution {
public:
    int partyHouse(int n, vector<vector<int>> &adj){
        vector<int> degree(n + 1, 0); // degree of each node (1-based indexing)
        // Step 1: Compute degrees of each node
        for(int i = 1; i <= n; i++){
            degree[i] = adj[i].size();
        }
        queue<int> q;
        // Step 2: Push all initial leaf nodes (degree == 1)
        for(int i = 1; i <= n; i++){
            if(degree[i] == 1){
                q.push(i);
                degree[i]--; // Mark as processed
            }
        }
        int root = 0;

        // Step 3: Remove leaves layer by layer until root (centroid) is found
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int node = q.front();
                q.pop();
                root = node; // Last processed node is one of the centroids
                for(int neighbor : adj[node]){
                    degree[neighbor]--;
                    if(degree[neighbor] == 1){
                        q.push(neighbor);
                    }
                }
            }
        }
        // Step 4: Do BFS from the root to find the max distance (height)
        vector<bool> visited(n + 1, false);
        queue<int> bfsQ;
        bfsQ.push(root);
        visited[root] = true;
        int ans = 0;
        while(!bfsQ.empty()){
            int size = bfsQ.size();
            for(int i = 0; i < size; i++){
                int node = bfsQ.front();
                bfsQ.pop();
                for(int neighbor : adj[node]){
                    if(!visited[neighbor]){
                        visited[neighbor] = true;
                        bfsQ.push(neighbor);
                    }
                }
            }
            ans++; // Each level represents a distance step
        }
        return ans - 1; // Final level incremented after last node, subtract 1
    }
};