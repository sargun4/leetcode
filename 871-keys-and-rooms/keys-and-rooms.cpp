#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int src,vector<bool> &vis){
        vis[src]=true;
        for(int &node:rooms[src]){
            if(!vis[node]){
                dfs(rooms,node,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        dfs(rooms,0,vis);
        for(bool x:vis){
            if(x==false){//1 room found which isnt visited
                return false;
            }
        }
        return true;
    }
};