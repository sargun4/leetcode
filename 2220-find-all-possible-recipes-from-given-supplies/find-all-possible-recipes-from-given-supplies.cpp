//kahn's-O(V+E)
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        unordered_set<string> st(begin(supplies),end(supplies));
        unordered_map<string,vector<int>> adj;//{ingred->recipe};
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){//go over all recipes
            for(string& ing:ingredients[i]){//and chekc each ingredient
                if(!st.count(ing)){//if ing not present in supplies set
                    //this recipe is dependet on the ingredient
                    adj[ing].push_back(i);
                    indegree[i]++;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<string> res;
        while(!q.empty()){
            int node=q.front(); q.pop();
            string recipe=recipes[node];
            res.push_back(recipe);
            for(int&neigh_idx:adj[recipe]){
                indegree[neigh_idx]--;
                if(indegree[neigh_idx]==0){
                    q.push(neigh_idx);
                }
            }
        }
        return res;
    }
};