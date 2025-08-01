// T: Building graph: O(N⋅K), where N is the number of accounts and K is average number of emails per account.
// BFS traversal: O(N⋅K log K) due to sorting emails per connected component.
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>> adj;//graph:{email->list of connected emails}
        unordered_map<string,string> map;//{email:name}
        //Build graph and map each email to a name in the same acc
        for(auto&acc:accounts){
            string name=acc[0];
            string firstEmail=acc[1];//1st email as ref for creating conncns
            int m=acc.size();
            //trav emails starting frm idx 1(skip name)
            for(int i=1;i<m;i++){
                string email=acc[i];
                map[email]=name;
                //create undir connecns bw 1st email n all others in same acc
                // if(i==1) continue;//skip 1st email(used as central node in graph)
                if(i>1){
                    adj[firstEmail].push_back(email);//connect 1st email to curr email
                    adj[email].push_back(firstEmail);//connect curr to 1st email
                }
            }
            //acc w only 1 email(no edges formed)
            if(acc.size()==2){
                string email=acc[1];
                if(!adj.count(email)){
                    adj[email]={};//still include it as a node w no edges;
                }
            }
        }
        unordered_set<string> vis;//to avoid revisiting emails
        vector<vector<string>> ans;//final merged accs
        //trav each component(grp of conn emails) usin bfs
        for(const auto&it:adj){
            const string &email=it.first;
            if(vis.count(email)) continue;//skip alr vis emails
            vector<string> component;//stores connctd emails for this acc
            queue<string> q;
            q.push(email);
            vis.insert(email);

            while(!q.empty()){
                string node=q.front();
                component.push_back(node);
                q.pop();
                for(auto&neigh:adj[node]){
                    if(!vis.count(neigh)){
                        q.push(neigh);
                        vis.insert(neigh);
                    }
                }
            }
            //sort n add user name to start(prepend)
            sort(component.begin(),component.end());
            // Add the owner's name at the beginning
            string name=map[email];
            component.insert(component.begin(),name);
            ans.push_back(component);
        }
        return ans;
    }
};