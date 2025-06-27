class Solution {
public:
    string res="";
     // Checks if subseq repeated k times is a subsequence of s
    bool isSubseq(string&s,string&sub,int k){
        int i=0; int j=0; int L=sub.length(); int n=s.length();
        while(i<n && j<k*L){
            if(s[i]==sub[j%L]){
                j++;
            }
            i++;
        }
        return j==k*L;
    }
    void backtrack(string &s,string&curr,vector<bool> &canUse,vector<int> &reqFreq,int k,int maxlen){
        int len=curr.length();
        if(len>maxlen) return;
        //check if curr string repeated k times is a subseq            
        if(((len>res.length()) || (len==res.length() && curr>res)) && isSubseq(s,curr,k)){
            res=curr;
        }
        for(int i=25;i>=0;i--){//try larger characters first for lexically grater
            if(canUse[i]==true && reqFreq[i]>0){
                //do
                char ch=i+'a';
                curr.push_back(ch);
                reqFreq[i]--;
                //explreo
                backtrack(s,curr,canUse,reqFreq,k,maxlen);
                //undo
                curr.pop_back();
                reqFreq[i]++;
            }   
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.length();
        int freq[26]={};
        for(char &ch:s){
            freq[ch-'a']++;
        }
        vector<bool> canUse(26,false);
        vector<int> reqFreq(26,0);
        for(int i=0;i<26;i++){
            if(freq[i]>=k){
                canUse[i]=true;
                reqFreq[i]=freq[i]/k;//atmost this can be used in a subseq
            }
        }
        int maxlen=n/k;//upper bound on res length is (total_chars/k)

        string curr;
        backtrack(s,curr, canUse,reqFreq,k,maxlen);
        return res;
    }
};