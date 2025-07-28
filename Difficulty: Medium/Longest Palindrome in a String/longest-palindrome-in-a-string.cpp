class Solution {
public:
    bool isPalind(string&s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string &s) {
        int n=s.size();
        unordered_map<string,int> map; //{substr:len}
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalind(s,i,j)){
                    int len=j-i+1;
                    string sub=s.substr(i,len);
                    map[sub]=len;
                }
            }
        }
        string ans = "";
        int maxlen = 0;
        for (auto it : map) {
            if (it.second > maxlen) {
                maxlen = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};