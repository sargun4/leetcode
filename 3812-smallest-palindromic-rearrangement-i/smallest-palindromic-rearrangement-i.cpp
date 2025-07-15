class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> freqmap;//{char,freq}
        for(auto &ch:s){
            freqmap[ch]++;
        }
        int oddctr=0;//only 1 char can hv odd freq in str for it to be palindr
        char midChar='.';
        //get oddfreq char- thatll be our mid char if it exists
        for(auto &[ch,freq]:freqmap){
            if(freq%2!=0){//odd
                oddctr++;
                midChar=ch;
            }
        }
        //if more than 1 char w odd freq,retunr empty str
        if(oddctr>1) return "";
        // else, form half the string using half the freq of each char & add the middle char (if it exists)
        string half="";
        for(auto &[ch,freq]:freqmap){
            half+=string(freq/2,ch);
        }
        //sort to get lexicographically smallest palindr
        sort(half.begin(),half.end());
        string ans=half;
        if(midChar!='.'){
            ans+=string(1,midChar);//add middle char if it exists
        }
        reverse(half.begin(),half.end());
        ans+=half;
        return ans;
    }
};