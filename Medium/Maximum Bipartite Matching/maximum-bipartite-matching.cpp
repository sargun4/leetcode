//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<bits/stdc++.h>
using namespace std;
  
class Solution {
public:
    int n,m;
    bool bpm(vector<vector<int>>&G,int u,bool vis[],int match[]){
        //try for every job 
        for(int v=0;v<n;v++){
            //if applicant u is intrested in job v and v isnt vis yet
            if(G[u][v] && !vis[v]){
                vis[v]=true;// Mark v as visited
                //if job v is not assigneed to an applicant OR prev assigned appliactn for job v (match[v]) has
                // an alternate job available.
                // since v is amrked as vis in the above line, match[v] in the foll recursive call will not 
                // get job 'v again.
                if(match[v]<0||bpm(G,match[v],vis,match)){
                    match[v]=u;
                    return true;
                }
            }
        }
        return false;
    }
	int maximumMatch(vector<vector<int>>&G){ 
        m=G.size(); 
        n=G[0].size();
        // An array to keep track of the 
        // applicants assigned to jobs. 
        // The value of match[i] is the 
        // applicant number assigned to job i,
        // the value -1 indicates nobody is
        // assigned.
        int match[n];
        //intially all jobs availablw
        memset(match, -1, sizeof(match));
        int res=0;//count of jobs allocated to applicants
        for(int u=0;u<m;u++){
            bool vis[n];
            memset(vis,0,sizeof(vis));
            //find if applicant u can get a job
            if(bpm(G,u,vis,match)){
                res++;
            }
        }
        return res;
	}
}; 

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends