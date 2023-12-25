// #include<bits/stdc++.h>
// using namespace std;
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> vpair; //elemnt and its idx pair
        for(int i=0;i<n;i++){
            vpair.push_back({nums[i],i});
        }
        sort(vpair.begin(),vpair.end());
        int grp_id=0;
        unordered_map<int,vector<pair<int,int>>> map;
        for(int i=0;i<n;i++){ 
            if(i==0||vpair[i].first-vpair[i-1].first>limit){
                grp_id++;
            }
            map[grp_id].push_back(vpair[i]);
        }
        for(auto p:map){
            vector<pair<int,int>> vp=p.second;
            vector<int> elmnt,id;
            for(auto pp:vp){
                elmnt.push_back(pp.first);
                id.push_back(pp.second);
            }
            sort(id.begin(),id.end());
            for(int j=0;j<elmnt.size();j++){
                ans[id[j]]=elmnt[j];
            }
        }
        return ans;
    }
};