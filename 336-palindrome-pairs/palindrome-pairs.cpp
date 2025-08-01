// Store each reversed word into a hash map.
// For each word, enumerate its prefix and suffix, and check if they are palindromes.
// If yes, then check if the other part is stored in the hash map, and add the pair into the result array.
class Solution {
public:
    bool isPalind(const string& s, int l, int r) {
        while(l<r){
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int> map;//{rev_word:idx}
        for(int i=0;i<n;i++){//store rev word w indices
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            map[rev]=i;
        }
        vector<vector<int>> ans;
    //for each word, split into prefix n suffix at every possible idx
        for(int i=0;i<n;i++){
            const string &word=words[i];
            int len=word.size();
            for(int j=0;j<=len;j++){
                // Split into prefix and suffix
                //If prefix is palind, check if rev suffix exists in map
                if(isPalind(word,0,j-1)){
                    string suffix=word.substr(j);
                    if(map.find(suffix)!=map.end() && map[suffix]!=i){
                        ans.push_back({map[suffix],i});
                    }
                }
            //if suffix is palind, check if rev prefix exists
                //avoid dupl pairs when j == len
                if(j!=len && isPalind(word,j,len-1)){
                    string prefix=word.substr(0,j);
                    if(map.find(prefix)!=map.end() && map[prefix]!=i){
                        ans.push_back({i,map[prefix]});
                    }
                }
            }
        }
        return ans;
    }
};