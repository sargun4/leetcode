class Solution {
public:
    int nonSpecialCount(int l, int r) {
        // calc limit up to which we need to find prime nos
        int lim = (int)(sqrt(r));
        //create a bool array to mark primeup to lim using Sieve of Eratosthenes
        vector<bool> v(lim + 1, true);
        v[0] = v[1] = false; // 0 and 1 are not prime nos

        // Sieve of Eratosthenes to mark non-prime nos
        for (int i=2;i*i<=lim; i++){
            if (v[i]){
                for (int j = i*i; j <= lim; j += i) {
                    v[j]=false;
                }
            }
        }
        // Count special nos in range [l, r]
        int ctr = 0;
        for (int i = 2; i <= lim; i++) {
            if (v[i]) {
                int square = i * i;
                if (square >= l && square <= r) {
                    ctr++;
                }
            }
        }
        // Total nos in range [l, r]
        int total = r - l + 1;
        // calc non-special nos
        return total - ctr;
    }
};