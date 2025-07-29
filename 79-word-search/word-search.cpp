#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
    bool find(vector<vector<char>>&board,int i,int j,int idx,string &word){
        int m=board.size();
        int n=board[0].size();
        // If we're at the last character, return true if it matches
        if(idx == word.length()) return true; //word found
        if( (i<0||j<0||i>=m||j>=n) || board[i][j]=='$'){
            return false;
        }
        //if curr char doesnt match - false
        if(board[i][j]!=word[idx]){
            return false;
        }
        char temp = board[i][j];
        board[i][j]='$';
        for(auto &dir:dirns){
            int ni=i+dir[0];
            int nj=j+dir[1];
            if(find(board,ni,nj,idx+1,word)){
                return true;
            }
        }
        board[i][j]=temp;//backtrack n unmark cell
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for (int i = 0;i<m;i++){
            for (int j = 0;j<n;j++){
                //start dfs frm the first character of word
                if(board[i][j]==word[0] && find(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};