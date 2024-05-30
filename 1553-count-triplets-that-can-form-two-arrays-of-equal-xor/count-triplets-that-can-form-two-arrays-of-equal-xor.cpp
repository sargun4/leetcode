class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int triplets=0;
        for (int i=0;i<n-1;i++){ 
            int ans=arr[i];
            for (int j=i+1;j<n;j++){
                ans=ans^arr[j]; 
                if (ans==0){
                    triplets+=j-i;
                }
            }
        } 
        return triplets;
    }
}; 