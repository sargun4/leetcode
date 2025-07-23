class Solution {
public:
    bool allZero(vector<int>&ctr){
        for(int&i:ctr){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
    int search(string &pat, string &txt) {
        int n=txt.size();
        vector<int> ctr(26,0);
        //count the freq of each char in pat
        for(int i=0;i<pat.length();i++){
            char ch=pat[i];
            ctr[ch-'a']++;
        }
        int i=0; int j=0;
        int res=0;
        int k=pat.length();
        while(j<n){
            ctr[txt[j]-'a']--;//reduce the freq of char we r at on jth idx of txt
            if(j-i+1==k){
                if(allZero(ctr)){
                    res++;
                }
                ctr[txt[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};