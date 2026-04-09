class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxL=height[0], maxR=height[n-1];
        int l=0, r=n-1;
        int trappedWater=0;
        while(l<r) {
            if(height[l]<height[r]) {
                maxL=max(height[l],maxL);
                trappedWater+=maxL-height[l];
                l+=1;
            } else {
                maxR = max(height[r],maxR);
                trappedWater+=maxR-height[r];
                r-=1;
            }
        }
        
        return trappedWater;
    }
};
