//type1
//-check does it exist in the map[id], if yes then return it
//-else if, return smallest in the set
//-if set is empty then -1

//type2
//remove the node from that component with the id

//DFS
class Solution {
public:
    //dfs to collect all connected stations into one component
    void dfs(int station,unordered_map<int,vector<int>> &adj,
    unordered_set<int> &vis,set<int> &gridSet){
        vis.insert(station);
        gridSet.insert(station);
        for(int neigh:adj[station]){
            if(!vis.count(neigh)){//neigh not yet vis
                dfs(neigh,adj,vis,gridSet);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        //make undir graph 
        unordered_map<int,vector<int>> adj;//{node:[neighbors]}
        for(auto e:connections){
            int u=e[0]; int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //build connected components(powergrids) using dfs
        vector<set<int>> powerGrid;//each grid is a set of active stations
        unordered_map<int,int> stationMap;//map frm station to its grid idx
        unordered_set<int> vis;//vis stations
        for(int station=1;station<=c;station++){
            if(vis.count(station)) continue;//alr part of somegrid,so skip this station
            set<int> gridSet;
            dfs(station,adj,vis,gridSet);
            //assign grid idx to each station in this grid
            int idx=powerGrid.size();
            for(int s:gridSet){
                stationMap[s]=idx;
            }
            powerGrid.push_back(gridSet);
        }
        vector<int> ans;//to store ans to queries of type1
        for(auto q:queries){
            int type=q[0];//1 or 2
            int station=q[1];
            int idx=stationMap[station];//which grid station belongs to 
            if(type==2){//remove station frm grid's active set-make offline
                powerGrid[idx].erase(station);//O(logn)
            }
            //now type=1
            else if(powerGrid[idx].count(station)>0){//if station still online,push in ans
                ans.push_back(station);
            }else if(powerGrid[idx].size()>0){//else, return the smallest st in same grid(since set is sorted)
                ans.push_back(*powerGrid[idx].begin());//get min elmnt in O(1)
            }else{//if set empty(no online sts left)
                ans.push_back(-1); //return -1
            }
        }
        return ans;
    }
};
// //bfs
// class Solution {
// public:
//     vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
//         //make undir graph 
//         unordered_map<int,vector<int>> adj;//{node:[neighbors]}
//         for(auto e:connections){
//             int u=e[0]; int v=e[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         vector<set<int>> powerGrid;//store each connected component as a set
//         unordered_set<int> vis;//track of alr vis stations 
//         unordered_map<int,int> stationMap;//map {station:grid_idx} of powerGrid;
//         //build connected components using Bfs
//         for(int station=1;station<=c;station++){//go over all stations
//             if(vis.count(station)) continue;//skip alr vis stations(they r alr part of a known grid)
//             queue<int> q;
//             vis.insert(station);
//             q.push(station);
//             set<int> gridSet;//hold all stations in curr grid
//             //bfs
//             while(!q.empty()){
//                 int u=q.front(); q.pop();
//                 gridSet.insert(u);
//                 for(int neigh:adj[u]){
//                     if(vis.count(neigh)==0){//neigh st not yet vis
//                         vis.insert(neigh); 
//                         q.push(neigh);
//                     }
//                 }
//             }
//             //after BFS ends, assign every station u a grid ID=idx of powerGrid
//             for(int u:gridSet){
//                 stationMap[u]=powerGrid.size();
//             }
//             powerGrid.push_back(gridSet);
//         }
//         vector<int> ans;//to store ans to queries of type1
//         for(auto q:queries){
//             int type=q[0];//1 or 2
//             int station=q[1];
//             int idx=stationMap[station];//which grid station belongs to 
//             if(type==2){//remove station frm grid's active set-make offline
//                 powerGrid[idx].erase(station);//O(logn)
//             }
//             //now type=1
//             else if(powerGrid[idx].count(station)>0){//if station still online,push in ans
//                 ans.push_back(station);
//             }else if(powerGrid[idx].size()>0){//else, return the smallest st in same grid(since set is sorted)
//                 ans.push_back(*powerGrid[idx].begin());//get min elmnt in O(1)
//             }else{//if set empty(no online sts left)
//                 ans.push_back(-1); //return -1
//             }
//         }
//         return ans;
//     }
// };