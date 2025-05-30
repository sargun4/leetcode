class Solution {
public:
    int n;
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n=edges.size();
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);

        vector<bool> vis1(n,false);
        vector<bool> vis2(n,false);

        dist1[node1]=0;
        dist2[node2]=0;

        dfs(edges,node1,dist1,vis1);
        dfs(edges,node2,dist2,vis2);

        int mindistnode=-1;
        int mindistTillNow=INT_MAX;

        for(int i=0;i<n;i++){
            int maxD=max(dist1[i],dist2[i]);
            if(mindistTillNow > maxD){
                mindistTillNow=maxD;
                mindistnode=i;
            }
        }
        return mindistnode;
    }
    void dfs(vector<int>& edges, int node,vector<int> &dist,vector<bool> &vis){
        vis[node]=true;
        
        int v=edges[node];
        if(v!=-1 && !vis[v]){
            vis[v]=true;
            dist[v]=1+dist[node];
            dfs(edges,v,dist,vis);
        }
    }
};