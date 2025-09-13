class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vowelsFreq;
        unordered_map<char,int> consonantFreq;
        for(char ch:s){
            if(ch=='a' || ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'){
                vowelsFreq[ch]++;
            }else{
                consonantFreq[ch]++;
            }
        }
        int consMaxfreq=0;
        for(auto it:consonantFreq){
            int freq=it.second;
            if(consMaxfreq<freq){
                consMaxfreq=freq;
            }
        }
        int vowelMaxfreq=0;
        for(auto it:vowelsFreq){
            int freq=it.second;
            if(vowelMaxfreq<freq){
                vowelMaxfreq=freq;
            }
        }
        return vowelMaxfreq+consMaxfreq;
    }
};