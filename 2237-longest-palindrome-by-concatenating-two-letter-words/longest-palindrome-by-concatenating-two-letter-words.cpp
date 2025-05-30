class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> map;
        int res=0;
        for(string &word:words){
            string rev=word;
            swap(rev[0],rev[1]);//just reversed the word to check for palindrme
            if(map[rev]>0){ //if the rev of that word exists in the list=>palind can be formed
                res+=4; //2+2
                map[rev]--;
            }else{ //rev not yet encountered or just doesnt exist in list,so we add the word and its freq to map;
                map[word]++;
            }
        }

        for(auto &it:map){
            string word=it.first;
            int freq=it.second;
            if(word[0]==word[1] && freq>0){ //equal char words=> ONLY ADD ONE of them
                res+=2; // only 2 added for palind 
                break;
            }
        }
        return res;
    }
};