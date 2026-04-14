class Solution {
    bool condition(int cap, int days, vector<int>&wts) {
        int calcDays=1, weightPerDay=0;
        for(int wt:wts) {
            weightPerDay+=wt;
            if(weightPerDay>cap) {
                calcDays+=1;
                weightPerDay=wt;
            }
            if(calcDays>days) return false;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        while(l<r) {
            int m = l+(r-l)/2;
            if(condition(m,days,weights)) r=m;
            else l=m+1;
        }
        return l;
    }
};