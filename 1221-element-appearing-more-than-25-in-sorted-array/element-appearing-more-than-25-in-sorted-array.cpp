#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {  
        int n=arr.size();
        int freq=n/4;
        unordered_map<int,int> map;  //map to store the frequency of each element in array
        for(int &num:arr){
            map[num]++;
            if(map[num]>freq){
                return num;
            }
        }
        return -1;
    }
};