class Solution {
    bool condition(vector<int>&piles, int h, int m) {
        int hours = 0;
        for(int i=0;i<piles.size();i++) {
            hours+=ceil(piles[i]/(double)m);
            if(hours>h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end())+1;
        while(l<r) {
            int m = l+(r-l)/2; // (l+r)/2
            if(condition(piles,h,m)) {
                r=m;
            } else l=m+1;
        }
        return l;
    }
};
// T.C: O(n*logn)+O(n) ~ O(n*logn)
// S.C: O(1)
