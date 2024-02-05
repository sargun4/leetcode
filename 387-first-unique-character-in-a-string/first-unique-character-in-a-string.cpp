class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26];
        int n=s.length();
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            arr[ch]++;
        }
        for(int i=0;i<n;i++){
            int ch=s[i];
            if(arr[ch-'a']==1){
                return i;
            }
        }
        return -1;
    }
};