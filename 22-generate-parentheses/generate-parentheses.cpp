 
#include <bits/stdc++.h>
using namespace std; 
// class Solution {
// public:
//     vector<string> res;
//     bool isvalid(string str){
//         int ctr=0;
//         for(char ch:str){
//             if(ch=='(') ctr++;
//             else ctr--;
//             if(ctr<0) return false;
//         }
//         return ctr==0;
//     }
//     void solve(string &curr,int n){
//         if(curr.length()==2*n){
//             if(isvalid(curr)){
//                 res.push_back(curr);
//             }
//             return;
//         }
//         curr.push_back('(');
//         solve(curr,n);
//         curr.pop_back();
        
//         curr.push_back(')');
//         solve(curr,n);
//         curr.pop_back();
//     }
//     vector<string> generateParenthesis(int n) {
//         string curr="";
//         solve(curr,n);
//         return res;
//     }
// };
class Solution {
public:
    void comb(int open,int close,vector<string> &res,string str){
        if (open == 0 and close == 0){
            res.push_back(str);
            return;
        }
        if (open > 0){
            str.push_back('(');
            comb(open-1,close,res,str);
            str.pop_back();
        }
        if (close > 0 && close>open){
            str.push_back(')');
            comb(open,close-1,res,str);
            str.pop_back();
        } 
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string val="";
        comb(n,n,res,val);
        return res;
    }
};
// class Solution {
// public:
//     void comb(int open,int close,vector<string> &res,string str){
//         if (open == 0 and close == 0){
//             res.push_back(str);
//             return;
//         }
//         if (open > 0){
//             comb(open-1,close,res,str+"(");
//         }
//         if (close > 0 && close>open){
//             comb(open,close-1,res,str+")");
//         } 
//     }
//     vector<string> generateParenthesis(int n) {
//         vector<string> res;
//         comb(n,n,res,"");
//         return res;
//     }
// };