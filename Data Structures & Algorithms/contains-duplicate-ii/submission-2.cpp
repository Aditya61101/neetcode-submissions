class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        unordered_map<int,int>freq;
        int n = nums.size();
        int i=0;
        for(int j=0;j<n;j++) {
            freq[nums[j]]+=1;
            if(abs(j-i)>k) {
                freq[nums[i]]--;
                i+=1;
            }
            if(freq[nums[j]]>1) return true;
        }
        return false;
    }
};