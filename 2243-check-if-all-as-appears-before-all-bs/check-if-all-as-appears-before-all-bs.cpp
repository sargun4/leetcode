class Solution {
public:
    bool checkString(string s) {
        int aidx=-1;//last seen index of 'a'
        int bidx=INT_MAX;//first seen index of 'b'
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                aidx=i;
            }else if(s[i]=='b'){
                bidx=i;
            }
            if(aidx>bidx){
                return false; // If any 'a' appears after a 'b', return false
            }
        }
        return true;
    }
};
// Iterate through the string s from the beginning to the end.
// Track the index of the last encountered 'a' and the first encountered 'b'.
// If at any point, the index of 'a' is greater than the index of 'b', return false because it means an 'a' appears after a 'b'.
// If the loop completes without finding any such condition, return true.