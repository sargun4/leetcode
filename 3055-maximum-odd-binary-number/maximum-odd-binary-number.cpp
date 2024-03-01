// https://leetcode.com/problems/maximum-odd-binary-number/?envType=daily-question&envId=2024-03-01

#include <bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length();
        string res=string(n,'0');
        int i=0;
        for(char &ch:s){
            if(ch=='1'){
                if(res[n-1]=='1'){//lsb='1' for it to to be an odd no.
                    res[i]='1';
                    i++;
                }else{
                    res[n-1]='1';
                }
            }
        }
        return res;
    }
};