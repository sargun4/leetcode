class Solution {
public: 
    int countPrefixSuffixPairs(vector<string>& words) {
        int n= words.size();
        int ctr=0;
        for(int i = 0; i<n;i++){
            for(int j = i+1; j<n;j++){
                string a=words[i];
                string b=words[j];
                if(a.length()>b.length()) continue;
                bool ispref=true; bool issuff=true;
                int n1=a.length();int n2=b.length();
                for(int k=0;k<n1;k++){
                    if(a[k]!=b[k]){
                        ispref=false;
                    }
                    if(a[n1-k-1]!=b[n2-k-1]){
                        issuff=false;
                    }
                }
                if(issuff && ispref){
                    ctr++;
                }
            }
        }
        return ctr; 
    }
};
 