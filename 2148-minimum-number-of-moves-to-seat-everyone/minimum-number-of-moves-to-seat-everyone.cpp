class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(seats),end(seats));
        sort(begin(students),end(students));
        int moves=0;
        int n=seats.size();
        for(int i=0;i<n;i++){
            moves+=abs(seats[i]-students[i]);
        }
        return moves;
    }
};