//lexicographically largest-which comes the latest in the dictionary
class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.length();
        if(numFriends==1) return word;
        string res;
        int longestposs=n-(numFriends-1);

        for(int i=0;i<n;i++){
            int canTakeLen=min(longestposs,n-i);
            res=max(res,word.substr(i,canTakeLen));
        }
        return res;
    }
};