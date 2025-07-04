#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<char,int> p;
    struct lambda{
        bool operator()(p &p1,p &p2){
            return p1.second<p2.second; //max heap based on freq vals
        }
    };
    string frequencySort(string s) {
        priority_queue<p,vector<p>,lambda> pq;//maxheap- desc ordr-max freq at top
        unordered_map<char,int> map;
        //freq updated in map
        for(char &ch:s){
            map[ch]++;
        }
        //fill in max heap frm map
        for(auto &it:map){
            pq.push({it.first,it.second});
        }
        string res="";
        while(!pq.empty()){
            p temp=pq.top();
            pq.pop();
            res+=string(temp.second,temp.first);
        }
        return res;
    }
};