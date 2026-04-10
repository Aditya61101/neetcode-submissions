class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        unordered_set<int>window;
        int n = nums.size();
        int i=0;
        for(int j=0;j<n;j++) {
            if(abs(j-i)>k) {
                window.erase(nums[i]);
                i+=1;
            }
            if(window.count(nums[j])) return true;
            window.insert(nums[j]);
        }
        return false;
    }
};