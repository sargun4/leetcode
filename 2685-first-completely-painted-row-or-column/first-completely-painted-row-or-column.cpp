class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int, int> rowcount, colcount; 
        unordered_map<int,pair<int,int>>mp; //{val,{i,j}}
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                mp[mat[i][j]]={i,j}; //store the coordinates of each number in the mat
            }
        }
        for(int i=0;i<arr.size();++i){
            int row=mp[arr[i]].first;
            int col=mp[arr[i]].second;
            
            // increment the row and col count for each occurrence
            ++rowcount[row];
            ++colcount[col];
    
            // if any row or col has all the numbers, return the current index          
            if(rowcount[row]==n || colcount[col]==m) return i;
        }      
        return -1;
    }
};


// class Solution {
// public:
//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         int n = mat.size(), m = mat[0].size();
//         unordered_map<int, pair<int, int> > mp;   // this map stores  ::  value -> {row, col}

//         // map creation process
//         for(int i=0; i<n; i++)  {
//             for(int j=0; j<m; j++)  {
//                 mp[mat[i][j]] = {i, j};
//             }
//         }
        
//         // initialy all row and col are not visited
//         vector<int> row(n, 0);  
//         vector<int> col(m, 0);
        
//         // traversing the array and adding one element to the corresponding row and col
//         for(int i=0; i<arr.size(); i++) {
//             pair<int, int> p = mp[arr[i]];  // we get the row and col of the cuurent element by the help of our map in O(1) time

//             int r = p.first, c = p.second;

//             row[r]++;   // adding one element in the corresponding row
//             if(row[r] >= m) return i;   // here the row is full if row contain m elements
            
//             col[c]++;   // adding one element in the corresponding row
//             if(col[c] >= n) return i;   // here the row is full if row contain m elements
//         }
        
//         return -1;
//     }
// };