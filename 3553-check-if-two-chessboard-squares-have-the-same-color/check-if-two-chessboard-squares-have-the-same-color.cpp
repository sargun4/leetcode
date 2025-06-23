class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        //cols frm a to h mapped to 1 to 8
        map<char, int> col_map = {
            {'a',1}, {'b',2}, {'c',3}, {'d',4},
            {'e',5}, {'f',6}, {'g',7}, {'h',8}
        };
        char horiz1 = coordinate1[0];//'a'
        char vert1 = coordinate1[1];//'3'
        char horiz2 = coordinate2[0];// e.g., 'b'
        char vert2 = coordinate2[1];// e.g., '6'

        //(col + row) sum for both coordinates
        int val1 = col_map[horiz1] + (vert1 - '0');//convert '3' → 3
        int val2 = col_map[horiz2] + (vert2 - '0');
        // Same color if both sums are even or both are odd
        return (val1 % 2) == (val2 % 2);
    }
};
