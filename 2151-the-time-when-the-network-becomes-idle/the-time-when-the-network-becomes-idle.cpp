//dist[i]=shortest dist frm master server(0) to data server(i);
//for each node(data server frm 1 to n), we hv
// 1. firstTimeRcvd=dist[i]*2 : time req to send msg to master(0) n get respons frm it
// 2. waitTime=firstTimeRcvd-1 : after 1st msg sent
// 3. numMsgsResent=waitTime/patience[i] : no of msgs resent after waitTime;
// when a data server(1 to n) recv a response frm 1st msg, it stops resending the other msgs. So completion time of data server=firstTimeRcvd+numMsgsResent*patience[i];
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience){
        int n=patience.size();
        vector<int> dist(n,INT_MAX);
        vector<vector<int>> adj(n);
        for(auto e:edges){//undir graph
            int u=e[0]; int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //bfs to get shortest path frm 0 to all other nodes(1 to n)
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(0);//master server=0
        vis[0]=1;
        int d=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int node=q.front(); q.pop();
                dist[node]=d;
                for(int&neigh:adj[node]){
                    if(!vis[neigh]){
                        q.push(neigh);
                        vis[neigh]=true;
                    }
                }
            }
            d++;
        }
        //get slowest completion time
        int slowest=0;
        for(int i=1;i<n;i++){
            int firstTimeRcvd=dist[i]*2;//round trip time
            int waitTime=firstTimeRcvd-1;//time beforr response rcvd by server i
            int numMsgsResent=waitTime/patience[i];
            int lastMsgTime = numMsgsResent * patience[i];//time when last msg sent
            int completionTime = firstTimeRcvd + lastMsgTime;//final response time
            slowest = max(slowest, completionTime);
        }
        return slowest+1;//network becomes idle 1sec after last repsonse
    }
};