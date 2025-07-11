class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        vector<int> odd;
        vector<int> even;
        int n=(int)A.size();
        for(int i=0;i<n;i++){
            if(A[i]%2==0){
                even.push_back(A[i]);
            }else{
                odd.push_back(A[i]);
            }
        }
        even.insert(even.end(),odd.begin(),odd.end());
        return even;
    }
};
// class Solution {
//     public:
//        vector<int> sortArrayByParity(vector<int> &A) {
//         for (int i = 0, j = 0; j < A.size(); j++)
//             if (A[j] % 2 == 0) swap(A[i++], A[j]);
//         return A;
//     }
// };