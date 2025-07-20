//kahn's-O(V+E)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        //convert supplies to a set for O(1) lookup
        unordered_set<string> st(begin(supplies),end(supplies));
        unordered_map<string,vector<int>> adj;//{ingred->recipe};
        //indegree[i]= no of missing ingredients
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){//go over all recipes
            for(string& ing:ingredients[i]){//and chekc each ingredient
                if(!st.count(ing)){//if ing not present in supplies set
                    //this recipe is dependet on the ingredient
                    //ingredient is not already in supplies,so we create dependency
                    adj[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }
        //initialize q with all recipes that hv indegree=0
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<string> res;
        //bfs (Kahn's Toposort)
        while(!q.empty()){
            int node=q.front(); q.pop();
            string recipe=recipes[node];
            res.push_back(recipe);
            //treat this recipe as a new "supply"
            //for all recipes depending on it, reduce their indegree 
            for(int&neigh_idx:adj[recipe]){
                indegree[neigh_idx]--;
                if(indegree[neigh_idx]==0){
                    q.push(neigh_idx);
                }
            }
        }
        //all recipes added to res are the ones we can make
        return res;
    }
};