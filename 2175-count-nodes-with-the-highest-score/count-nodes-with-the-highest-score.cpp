class Solution {
     int dfs(int src,vector<vector<int>>& graph,vector<int>& size){
         int ans = 1;
         for(auto child:graph[src]){
             ans += dfs(child,graph,size);
         }
         return size[src] = ans; 
     }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> size(n,0);  //size[i]=size of subtree(rooted at i node) + 1
        vector<vector<int>> graph(n); //stores left and right child of a node
        for(int i=1;i<n;i++){
            graph[parents[i]].push_back(i);
        }
        dfs(0,graph,size);  //calc size of each subtree
        long long ctr = 0, maxi = 0;
        for(int i=0;i<n;i++){
            long long prod = 1; 
            prod = max(prod,(long long)n - size[i]); //calc leftover nodes excluding child nodes 
            for(auto node:graph[i]){
                prod = prod * size[node]; //mult w size of subtree
            }
            if(prod > maxi){
                maxi = prod;
                ctr = 1;
            }
            else if(prod == maxi){
                ctr++;
            }
        }
        return ctr;
    }
};