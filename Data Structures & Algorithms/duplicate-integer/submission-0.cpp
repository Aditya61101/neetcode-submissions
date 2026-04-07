class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool>mp;
        for(int num:nums) {
            if(mp.count(num)) return true;
            mp[num]=true;
        }
        return false;
    }
};