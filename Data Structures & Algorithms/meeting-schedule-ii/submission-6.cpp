/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;
        vector<int>sTimes, eTimes;
        for(auto &v:intervals) {
            sTimes.push_back(v.start);
            eTimes.push_back(v.end);
        }
        sort(sTimes.begin(),sTimes.end());
        sort(eTimes.begin(),eTimes.end());
        int rooms=0,end=0;
        for(int i=0;i<n;i++){
            if(sTimes[i]<eTimes[end]) rooms+=1;
            else end+=1;
        }
        return rooms;
    }
};
