class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxL=height[0], maxR=height[n-1];
        int l=0, r=n-1;
        int trappedWater=0;
        while(l<r) {
            if(maxL<maxR) {
                l+=1;
                maxL=max(height[l],maxL);
                int water = maxL-height[l];
                trappedWater+=water;
            } else {
                r-=1;
                maxR = max(height[r],maxR);
                int water = maxR-height[r];
                trappedWater+=water;
            }
        }
        
        return trappedWater;
    }
};
