#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> lostcount;
        for(auto edge:edges){
            lostcount[edge[1]]++;
        }
        int champCtr=0,champ=-1;
        for(int team=0;team<n;team++){
            if(lostcount[team]==0){
                champCtr++;
                champ=team;
            }
        }
        return (champCtr==1) ? champ : -1;
    }
};