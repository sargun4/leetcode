class Solution {
public:
    string res="";
     // Checks if subseq repeated k times is a subsequence of s
    bool isSubseq(string&s,string&sub,int k){
        int i=0; int j=0; int L=sub.length(); int n=s.length();
        while(i<n && j<k*L){
            if(s[i]==sub[j%L]){//matched one char of sub
                j++;//move in sub
            }
            i++;//move ahead in s regardless
        }
        //if we matched all k * L chars, its a valid subseq;
        return j==k*L;
    }
    void backtrack(string &s,string&curr,vector<bool> &canUse,vector<int> &reqFreq,int k,int maxlen){
        int len=curr.length();
        if(len>maxlen) return;//if curr string too long stop exploring;
        //check if curr string repeated k times is a subseq & better than curr best      
        if(((len>res.length()) || (len==res.length() && curr>res)) && isSubseq(s,curr,k)){
            res=curr;
        }
        for(int i=25;i>=0;i--){//try larger characters first for lexically grater
            if(canUse[i]==true && reqFreq[i]>0){
                //do
                char ch=i+'a';
                curr.push_back(ch);
                reqFreq[i]--;
                //explore w this charr added
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
        vector<int> reqFreq(26,0);//max no of times each char can appear in x
        for(int i=0;i<26;i++){
            if(freq[i]>=k){
                canUse[i]=true;//if char can be used
                reqFreq[i]=freq[i]/k;//atmost this can be used in a subseq
            }
        }
        int maxlen=n/k;//upper bound on res length is (total_chars/k)

        string curr;
        backtrack(s,curr, canUse,reqFreq,k,maxlen);
        return res;
    }
};