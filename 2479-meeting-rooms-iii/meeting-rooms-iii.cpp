// unused_rooms & used_rooms = minheaps, with unused_rooms representing available rooms sorted by room number, & used_rooms storing rooms in use along with timey become available again.
#define p pair<long long,int> 
//{end_time,roomno}
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings){
        vector<int> meetingCount(n,0);//to track how many meetings each room handles
        //2 minheaps
        priority_queue<p, vector<p>, greater<>> usedRooms; //rooms in use:{end_time, room}
        //available room numbers (smallest idx at top)
        priority_queue<int, vector<int>, greater<>> unusedRooms;//free rooms sorted by room number

        for(int i=0;i<n;i++){//initially all rooms are free
            unusedRooms.push(i);
        }
        sort(meetings.begin(),meetings.end());//to get earlier start times first 
        for(auto meeting:meetings){
            int start=meeting[0], end=meeting[1];
            //free up any rooms that are now available (finished before current start)
            while(!usedRooms.empty() && usedRooms.top().first<=start){
                int room=usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);//room is now free,add back to available pool
            }
            //try to assign a free room (lowest idx preferred)
            if(!unusedRooms.empty()){
                //there's a free room: assign meeting to lowest-numbered room
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end,room});//meeting ends at `end`
                meetingCount[room]++;
            }else{//no rooms free, delay meeting
// We find room with earliest availability time & adjust availability time of this room based on duration of delayed meeting, & push room back into used_rooms. This ensures that meetings with earlier original start times are given priority when rooms become available & delayed meetings hv same duration as original meeting.
                auto [roomAvailableTime,room]=usedRooms.top();
                usedRooms.pop();
                //delay mmeting, but keep same duration
                int duration=end-start;
                long long newEndTime=roomAvailableTime+duration;
                usedRooms.push({newEndTime,room});
                meetingCount[room]++;
            }
        }
        //find room that handled most meetings
        int maxMeetingCtr=0; int maxMeetingCtrRoom=0;
        for(int i=0;i<n;i++){
            if(meetingCount[i]>maxMeetingCtr){
                maxMeetingCtr=meetingCount[i];
                maxMeetingCtrRoom=i;
            }
        }
        return maxMeetingCtrRoom;
    }
};