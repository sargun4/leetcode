class Solution {
public:
    bool isPalind(int ans){//O(log n)
        string s=to_string(ans);
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool findPrime(int ans){
        bool isPrime=true;
        for(int i=2;i*i<=ans;i++){
            if(ans%i==0){// Divisible => Not prime
                isPrime=false;
                break;
            }
        }
        return isPrime;
    }
    int primePalindrome(int n) {
        int ans = n;//start checking from n
        //The only even-digit prime palindrome is 11
        if(n<=11) {
            vector<int> small = {2, 3, 5, 7, 11};
            for (int x:small) {
                if (x>=n) return x;
            }
        }
        //loop indefinitely until we find a prime palindrome
        while (true) {
            // Skip even-length palindromes as they are divisible by 11
            int len=to_string(ans).size();
            if (len % 2 == 0) {
                ans = pow(10, len); // Move to next power of 10 (odd-length)
                continue;
            }

            // If ans is both prime and palindrome, return it
            if (isPalind(ans) && findPrime(ans)) {
                return ans;
            }

            ans++; // Try next number
        }

        return -1; // Unreachable, safety return
    }
};