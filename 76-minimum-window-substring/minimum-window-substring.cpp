class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int reqCount=t.length();
        if(reqCount>n){
            return "";
        }
        unordered_map<char,int> map;
        for(char&ch:t){//stores str t's chars initially in map
            map[ch]++;
        }
        int i=0; int j=0;
        int minWindowSize=INT_MAX;
        int start_i=0;
        while(j<n){
            char ch=s[j];
            if(map[ch]>0){//need this char
                reqCount--;
            }
            map[ch]--;
            while(reqCount==0){//start shrinking the window
                int currWindowSize=j-i+1;
                if(minWindowSize>currWindowSize){
                    minWindowSize=currWindowSize;
                    start_i=i;
                }
                map[s[i]]++;//
                
                if(map[s[i]]>0){
                    reqCount++;
                }
                i++;//shrink window
            }
            j++;
        }

        return minWindowSize==INT_MAX ? "":s.substr(start_i,minWindowSize);
    }
};