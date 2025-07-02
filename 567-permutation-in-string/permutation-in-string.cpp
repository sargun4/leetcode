//slding window
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m) return false;
        vector<int> s1freq(26,0);
        vector<int> s2freq(26,0);
        for(char&ch:s1){
            s1freq[ch-'a']++;
        }
        int i=0,j=0;
        while(j<m){
            s2freq[s2[j]-'a']++;
            if(j-i+1>n){//shrink the window
                s2freq[s2[i]-'a']--;
                i++;
            }
            if(s1freq==s2freq){
                return true;
            }
            j++;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int n=s1.length();
//         int m=s2.length();
//         if(n>m) return false;
//         sort(begin(s1),end(s1));
//         for(int i=0;i<=m-n;i++){
//             string sub=s2.substr(i,n);
//             sort(begin(sub),end(sub));
//             if(s1==sub){
//                 return true;
//             }
//         }
//         return false;
//     }
// };


// // //TLE
// // class Solution {
// // public:
// //     int n;
// //     bool res;
// //     void solve(int idx,string &s1,string &s2){
// //         if(idx==n){
// //             if(s2.find(s1)!=string::npos){//if wer able to find s1 in s2
// //                 res=true;
// //             }
// //             return; 
// //         }
// //         for(int i=idx;i<n;i++){
// //             swap(s1[i],s1[idx]);
// //             solve(idx+1,s1,s2);
// //             swap(s1[i],s1[idx]);
// //             if(res==true){
// //                 return;
// //             }
// //         }
// //     }
// //     bool checkInclusion(string s1, string s2) {
// //         n=s1.length();
// //         res=false;
// //         solve(0,s1,s2);
// //         return res;
// //     }
// // };