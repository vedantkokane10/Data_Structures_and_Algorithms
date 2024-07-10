/*
There is one meeting room in a firm. There are n meetings in the form of (start[i], 
end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a
particular time? Return the maximum number of meetings that can be held in the meeting room.

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :
Input: n = 6, start[] = {1,3,0,5,8,5}, end[] =  {2,4,6,7,9,9}
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2),(3, 4), (5,7) and (8,9)

Input: n = 3, start[] = {10, 12, 20}, end[] = {20, 25, 30}
Output: 1
Explanation: Only one meetings can be held with given start and end timings.

*/

/*
Approach - 
Sort the meetings based on the end time (i.e shortest meetings first)
Set count = 1 considering first meeting, store current meeting end time and iterate over the array 
check if the iterated meeting's start time greater than current meeting end time if yes the increment count and
update current meeting end time to iterated meeting's end time.
At end return count.
*/

const static bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int,int>> meetings(n);
    for(int i=0;i<n;i++){
        meetings[i] = {start[i],end[i]};
    }
    sort(meetings.begin(),meetings.end(),cmp);
    int cnt = 1;
    int currentEndTime = meetings[0].second;
    for(int i=1;i<n;i++){
        if(currentEndTime < meetings[i].first){
            cnt++;
            currentEndTime = meetings[i].second;
        }
    }
    return cnt;
}
