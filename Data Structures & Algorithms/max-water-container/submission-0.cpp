class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i=0, j=n-1;
        int maxArea = INT_MIN;
        while(i<j) {
            maxArea = max(maxArea, (j-i)*min(heights[j],heights[i]));
            if(heights[i]<=heights[j]) {
                i+=1;
            } else {
                j-=1;
            }
        }
        return maxArea;
    }
};
