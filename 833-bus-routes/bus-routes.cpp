#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        unordered_map<int,vector<int>> adj; //(stops,indices)
        for(int route=0;route<routes.size();route++){
            for(auto &stop:routes[route]){
                adj[stop].push_back(route);
            }
        }
        queue<int> q;
        vector<bool> vis(501,false);
        for(auto &route:adj[source]){
            q.push(route);
            vis[route]=true;
        }
        int busctr=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int route=q.front();
                q.pop();
                for(auto &stop:routes[route]){
                    if(stop==target){
                        return busctr;
                    }
                    for(auto &nextroute:adj[stop]){
                        if(vis[nextroute]==false){
                            vis[nextroute]=true;
                            q.push(nextroute);
                        }
                    }
                }
            }
            busctr++;
        }
        return -1;//no path found
    }
};