class Solution {
public:
    //helper to update the top two maximum path lengths for a node
    void updateTopTwo(vector<int>& longest, vector<int>& secondLongest, int node, int length) {
        if (length >= longest[node]) {
            secondLongest[node] = longest[node];
            longest[node] = length;
        } else if (length >= secondLongest[node]) {
            secondLongest[node] = length;
        }
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> longest(n, 1);//longest downward path frm node
        vector<int> secondLongest(n, 1); //2nd longest downward path frm node
        vector<int> indegree(n, 0);//no of children of each node
        //1. calc child count (indegree)
        for (int i = 1; i < n; i++) {
            indegree[parent[i]]++;
        }
        //2. push all leaf nodes into q
        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int maxPath = 1;//ans starts with at least 1 (single node)
        //3. Process nodes frm leaves towards the root
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int p = parent[node];  //parent of curr node
            if (p == -1) continue; //skip root's parent (invalid)

            int pathlen = 1;
            //if the chars differ, extend path len
            if (s[node] != s[p]) {
                pathlen += longest[node];
            }
            //update parent's top two longest paths
            updateTopTwo(longest, secondLongest, p, pathlen);
            //update maxPath with parent's two longest child paths
            maxPath = max(maxPath, longest[p] + secondLongest[p] - 1);
            //reduce indegree of parent and add it to q if all children are processed
            indegree[p]--;
            if (indegree[p]==0) {
                q.push(p);
            }
        }
        return maxPath;
    }
};

//mle
// class Solution {
// public:
//     int res=0;//ans-max path len
//     //dfs to compute longest valid downward path starting at 'node'
//     int dfs(vector<vector<int>> &adj,int node,int parent,string s){
//         int longest=0;//longest child path
//         int secondLongest=0;//2nd longest child path
//         for(int&child:adj[node]){//go over each neigh of node
//             if(child==parent) continue;//avoiding going back to parent
//             int child_longest_len=dfs(adj,child,node,s);//longest path rcvd frm this child
//             if(s[child]==s[node]){//adjacent nodes cant hv same chars of alphabet
//                 continue;
//             }
//             //update top 2 longest paths
//             if(child_longest_len>longest){
//                 secondLongest=longest;
//                 longest=child_longest_len;
//             }else if(child_longest_len>secondLongest){
//                 secondLongest=child_longest_len;
//             }
//         }
//     //update res using two best child paths + curr node
//         res = max(res, 1 + longest + secondLongest);

//         //the longest downward path including curr node
//         return 1 + longest;
//     }
//     int longestPath(vector<int>& parent, string s) {
//         int n=parent.size();
//         vector<vector<int>> adj(n);
//         for(int i=1;i<n;i++){
//             int u=i;
//             int v=parent[i];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         res=1;//atleast 1 node is always a path
//         dfs(adj,0,-1,s);//dfs frm root node-0 w parent -1;
//         return res;
//     }
// };