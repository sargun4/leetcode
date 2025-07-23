// T-O(n*26)
// S-O(26)
class Solution {
public:
    //to check if all char counts are 0 (anagram condn)
    bool allZero(vector<int>&ctr){
        for(int &i:ctr){
            if(i!=0){//if any 1 elmnt found thats not 0,return false
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();
        vector<int> ans;//store starting indices of anagrams
        if(n<k) return ans;//edge case- pattern itself longer than str-no anagrams can be found-return empty ans;
        
        vector<int> ctr(26,0);//count the freq of each char in p;
        for(char ch : p){
            ctr[ch-'a']++;
        }
        int i=0;//left ptr
        int j=0;//right ptr
        //sliding window over s
        while(j<n){
            ctr[s[j]-'a']--;//decrease the count of the curr char at j in s;
            if(j-i+1 == k){//if window size=len(p), check if all chars of p are present in this substr - if all the ctr in count of it are zero-it is anagram
                if(allZero(ctr)){
                    ans.push_back(i);
                }
                ctr[s[i]-'a']++;//reset it back to og once that char is not in our window
                i++;
            }
            j++;
        }
        return ans;
    }
};