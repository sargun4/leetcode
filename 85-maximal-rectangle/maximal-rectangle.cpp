#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> get_nsr(vector<int> &ht){//nearest smallest to right arr
        stack<int> st;
        int n=ht.size();
        vector<int>nsr(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                nsr[i]=n;
            }else{
                while(!st.empty() && ht[st.top()] >= ht[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsr[i]=n;
                }else{
                    nsr[i]=st.top();
                }
            }
            st.push(i);
        }
        return nsr;
    }
    vector<int> get_nsl(vector<int> &ht){//nearest smallest to left arr
        stack<int> st;
        int n=ht.size();
        vector<int>nsl(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                nsl[i]=-1;//out of boundddds
            }else{
                while(!st.empty() && ht[st.top()] >= ht[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsl[i]=-1;
                }else{
                    nsl[i]=st.top();
                }
            }
            st.push(i);
        }
        return nsl;
    }
    int find_maxarea(vector<int>&ht){
        // width=nsr[i]-nsl[i]-1;
        vector<int> nsr=get_nsr(ht);
        vector<int> nsl=get_nsl(ht);
        int n=ht.size();
        vector<int> width(n);
        for(int i=0; i<n; i++){
            width[i]=nsr[i]-nsl[i]-1;
        }
        int maxarea=0;
        for(int i=0; i<n; i++){
            int area=width[i]*ht[i];
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ht(n);
        //add first row in ht-1d
        for(int i=0; i<n; i++){
            ht[i]=(matrix[0][i]=='1') ?1:0;
        }
        int maxarea=find_maxarea(ht);
        for(int row=1;row<m;row++){
            for(int col=0;col<n;col++){
                if(matrix[row][col]=='0'){
                    ht[col]=0;
                }else{
                    ht[col]+=1;
                }
            }
            maxarea=max(maxarea,find_maxarea(ht));
        }
        return maxarea;
    }
};