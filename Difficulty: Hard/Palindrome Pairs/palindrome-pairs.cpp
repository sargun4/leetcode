//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    // Function to check if a palindrome pair exists
    bool isPalindrome(string &s){
       int i=0;
       int j = s.size()-1;
       while(i<j){
           if(s[i++]!=s[j--])
               return false;
       }
       return true;
   }
//  reverse all strings , insert in the hashmap
//  now create all possible prefixes of the string (substr(0,j) →ex: for “geek” →"",g ,ge,gee,geek will be the prefixes)
//  create all possible suffixes of the string (substr(j) →ex:"geek"→geek,eek,ek,k,"";
//  now check if prefix is a palindrome and the suffix is present in the hashmap //then the pair forms a palindrome
//  also check if suffix is a palindrome and the prefix is present in the hashmap //then the pair forms a palindrome 
   bool palindromepair(int N, string arr[]) {
       unordered_map<string,int> mymap;
       for(int i=0;i<N;i++){
           auto s = arr[i];
           reverse(s.begin(),s.end());
           mymap[s]=i;
          
       }
       
       for(int i=0;i<N;i++){ //for string1 string2 string 3....
           for(int j=0;j<arr[i].size();j++){ 
               string s1 = arr[i].substr(0,j); 
               string s2 = arr[i].substr(j); 
          
               if(mymap.count(s1) && isPalindrome(s2) && mymap[s1]!=i) return true;
               if(mymap.count(s2) && isPalindrome(s1) && mymap[s2]!=i) return true;
           }
       }
       return false;
   }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends