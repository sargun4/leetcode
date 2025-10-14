class Solution {
public:
    bool scoreBalance(string s){
        int n=s.size();
        int total=0;
        for(char c:s){//total score of all chars
            total+=(c-'a'+1);
        }
        int leftS=0;
        //s split at every idx
        for(int i=0;i<n-1;i++){
            leftS+=(s[i]-'a'+1);//add curr char to left sum
            int rightS=total-leftS;
            if(leftS==rightS){
                return true;
            }
        }
        return false;
    }
};