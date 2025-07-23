class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int res=0;
        vector<int> map(3,0);
        int i=0; int j=0;
        while(j<n){
            char ch=s[j];
            map[ch-'a']++;
            //all 3 chars are rpresent at least ince
            while(map[0]>0 && map[1]>0 && map[2]>0){
                res+=(n-j);//(n-j) valid windows
                map[s[i]-'a']--; //reduce the freq
                i++;
            }
            j++;
        }
        return res;
    }
};