/*You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.



Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0.
Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1.
**********LEETCODE POTD(18/02/2024)**********
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct room
{
    int room_id;
    ll end_time;
    room(int _room_id, ll _end_time)
    {
        room_id = _room_id;
        end_time = _end_time;
    }
    room() {}
    bool operator<(const room &other) const
    {
        if (end_time != other.end_time)
            return end_time > other.end_time;
        return room_id > other.room_id;
    }
};
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        map<int, int> room_cnt;
        room_cnt.clear();
        priority_queue<room> pq;
        priority_queue<int, vector<int>, greater<int>> left_rooms;

        for (int i = 0; i < n; ++i)
            left_rooms.push(i);
        for (int i = 0; i < meetings.size(); ++i)
        {
            while (!pq.empty())
            {
                auto top = pq.top();
                if (top.end_time <= meetings[i][0])
                {
                    pq.pop();
                    left_rooms.push(top.room_id);
                }
                else
                    break;
            }

            ll cur_st_time;
            if (left_rooms.empty())
            {
                auto top = pq.top();
                pq.pop();
                left_rooms.push(top.room_id);
                cur_st_time = top.end_time;
            }
            else
                cur_st_time = meetings[i][0];

            auto top = left_rooms.top();
            left_rooms.pop();
            room_cnt[top]++;
            pq.push(room(top, (ll)cur_st_time + (ll)meetings[i][1] - (ll)meetings[i][0]));
        }
        int max_ans = -1, max_id = 0;
        for (int i = 0; i < n; ++i)
            if (room_cnt[i] > max_ans)
            {
                max_ans = room_cnt[i];
                max_id = i;
            }
        return max_id;
    }
};