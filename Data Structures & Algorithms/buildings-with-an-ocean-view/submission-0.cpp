class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int>ans;
        int global_max=INT_MIN,n=heights.size();
        for(int i=n-1;i>=0;i--){
            if(heights[i]>global_max){
                ans.push_back(i);
                global_max=heights[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};