#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankset(bank.begin(), bank.end());//for quick access
        unordered_set<string> vis;
        queue<string> q;
        q.push(start);
        vis.insert(start);
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==end) return lvl;
                for(char ch:"ACGT"){
                    for(int i=0; i<curr.length(); ++i){
                        string neigh=curr;
                        neigh[i]=ch;
                        if(vis.find(neigh)==vis.end() &&
                        bankset.find(neigh)!=bankset.end()){ //if not yet visited and present in bankset
                            vis.insert(neigh);
                            q.push(neigh);
                        }
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};