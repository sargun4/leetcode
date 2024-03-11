#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int> indegree(n,0);
        vector<vector<int>> graph(n);
        for(vector<int>& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> zeroindegree;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                zeroindegree.push(i);
            }
        }
        vector<vector<int>> counts(n,vector<int>(26,0));
        for(int i=0; i<n; i++){
            counts[i][colors[i]-'a']++;
        }
        int maxctr=0;
        int vis=0;
        while(!zeroindegree.empty()){
            int u=zeroindegree.front();
            zeroindegree.pop();
            vis++;
            for(int v:graph[u]){
                for(int i=0;i<26;i++){
                    counts[v][i]=max(counts[v][i],counts[u][i]+(colors[v]-'a'==i?1:0)); 
                }
                indegree[v]--;
                if(indegree[v]==0)
                    zeroindegree.push(v);
            }
            maxctr=max(maxctr,*max_element(counts[u].begin(),counts[u].end()));
        }
        return vis==n ? maxctr:-1; //if cycle does exist,then return -1
    }
};