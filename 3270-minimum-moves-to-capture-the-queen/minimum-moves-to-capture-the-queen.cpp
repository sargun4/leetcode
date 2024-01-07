#include <iostream>
// Rook Capture:
// If the rook and queen are in the same row (a == e), the code checks if they are not in the same column (a != c) or if they are in the same 
// column but there is no bishop in between (max(b, f) < d || min(b, f) > d).
// If the above conditions are met, it returns 1, indicating that the queen can be captured in one move.
// If the rook and queen are in the same column (b == f), the code checks if they are not in the same row (b != d) or if they are in the same 
// row but there is no bishop in between (max(a, e) < c || min(a, e) > c).
// If the above conditions are met, it returns 1.

// Bishop Capture:
// The code then checks if the bishop and queen are on the same diagonal.
// It uses four while loops to iterate over each possible diagonal direction that the bishop can move (up-right, up-left, down-right, down-left).
// For each direction, it checks if the rook is in between the bishop and the queen. If yes, it sets ff (flag) to 1.
// If the queen is found in the diagonal path, it returns 1 plus the value of ff, indicating that the queen can be captured in one move.
// Default Case:
// If none of the above conditions are met, it returns 2, indicating that it would take at most 2 moves to capture the queen.

class Solution {
public:
    // Function to calculate the minimum moves to capture the queen
    int minMovesToCaptureTheQueen(int rookX, int rookY, int bishopX, int bishopY, int queenX, int queenY) {
        
        // Check if rook and queen are in the same row and there is no bishop in between
        if(rookX == queenX) {
            if(rookX != bishopX || (rookX == bishopX && (std::max(rookY, queenY) < bishopY || std::min(rookY, queenY) > bishopY))) {
                return 1; // Queen can be captured in one move
            }
        } 
        // Check if rook and queen are in the same column and there is no bishop in between
        else if(rookY == queenY) {
            if(rookY != bishopY || (rookY == bishopY && (std::max(rookX, queenX) < bishopX || std::min(rookX, queenX) > bishopX))) {
                return 1; // Queen can be captured in one move
            }
        }
        
        // Check if bishop and queen are on the same diagonal
        int x = bishopX, y = bishopY, bishopBlocked = 0;
        while(x <= 8 && y <= 8) { // Bishop moves ⬊
            if(x == rookX && y == rookY) {
                bishopBlocked = 1; // Rook is in between bishop and queen
            }
            if(x == queenX && y == queenY) {
                return 1 + bishopBlocked; // Queen can be captured in one move
            }
            x++, y++;
        }
        
        x = bishopX, y = bishopY, bishopBlocked = 0;
        while(x >= 1 && y >= 1) { // Bishop moves ⬉
            if(x == rookX && y == rookY) {
                bishopBlocked = 1; // Rook is in between bishop and queen
            }
            if(x == queenX && y == queenY) {
                return 1 + bishopBlocked; // Queen can be captured in one move
            }
            x--, y--;
        }
        
        x = bishopX, y = bishopY, bishopBlocked = 0;
        while(x <= 8 && y >= 1) { // Bishop moves ⬋
            if(x == rookX && y == rookY) {
                bishopBlocked = 1; // Rook is in between bishop and queen
            }
            if(x == queenX && y == queenY) {
                return 1 + bishopBlocked; // Queen can be captured in one move
            }
            x++, y--;
        }
        
        x = bishopX, y = bishopY, bishopBlocked = 0;
        while(x >= 1 && y <= 8) { // Bishop moves ⬈
            if(x == rookX && y == rookY) {
                bishopBlocked = 1; // Rook is in between bishop and queen
            }
            if(x == queenX && y == queenY) {
                return 1 + bishopBlocked; // Queen can be captured in one move
            }
            x--, y++;
        }
        
        return 2; // Queen can be captured in at most 2 moves
    }
};
 
//  // We just capture queen using rook and bishop. maximum step in any situation is 2 because rook move vertically or horizontally so we can capture queen using rook at most 2 moves.
// // But we need to check for only one move possible to capture queen (possibilities)
// // if queen and rook in one row or col so it's possible to capture queen in one move but bishop not in b/w them.
// // if bishop and queen lie in same digonal so it's possible to capture queen in one move but rook not in b/w them.
// class Solution {
// public:
//     int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        
//         // if rook and queen in one row or col and bishop not in b/w them
//         if(a == e) {
//             if(a != c || (a == c &&  (max(b, f) < d || min(b, f) > d))) return 1;
//         } else if(b == f) {
//             if(b != d || (b == d && (max(a, e) < c || min(a, e) > c))) return 1;
//         }
        
//         // if bishop and queen in same digonal
//         int x = c, y = d, ff = 0;
//         while(x <= 8 && y <= 8) { // bishop move ⬊
//             if(x == a && y == b) ff = 1; // if rook in b/w
//             if(x == e && y == f) return 1 + ff;
//             x++, y++;
//         }
        
//         x = c, y = d, ff = 0;
//         while(x >= 1 && y >= 1) { // bishop move ⬉
//             if(x == a && y == b) ff = 1; // if rook in b/w
//             if(x == e && y == f) return 1 + ff;
//             x--, y--;
//         }
        
//         x = c, y = d, ff = 0;
//         while(x <= 8 && y >= 1) { // bishop move ⬋
//             if(x == a && y == b) ff = 1;
//             if(x == e && y == f) return 1 + ff; // / if rook in b/w
//             x++, y--;
//         }
        
//         x = c, y = d, ff = 0;
//         while(x >= 1&& y <= 8) { // bishop move ⬈
//             if(x == a && y == b) ff = 1;
//             if(x == e && y == f) return 1 + ff; /// if rook in b/w
//             x--, y++;
//         }
//         return 2;
//     }
// };