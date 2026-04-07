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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &p1,auto &p2){
            return p1.start<p2.start;
        });
        for(int i=0;i<n-1;i++){
            if(intervals[i].end>intervals[i+1].start) return false;
        }
        return true;
    }
};
