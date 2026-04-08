class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        unordered_set<int> seen;
        unordered_set<string> triplets;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> complement_set;
            for (int j = i + 1; j < nums.size(); ++j) {
                int complement = -(nums[i] + nums[j]);
                if (complement_set.find(complement) != complement_set.end()) {
                    // Found a triplet
                    vector<int> triplet = {nums[i], nums[j], complement};
                    sort(triplet.begin(), triplet.end());
                    string key = to_string(triplet[0]) + "," + 
                                    to_string(triplet[1]) + "," + 
                                    to_string(triplet[2]);
                    if (triplets.find(key) == triplets.end()) {
                        triplets.insert(key);
                        result.push_back(triplet);
                    }
                }
                complement_set.insert(nums[j]);
            }
        }
        return result;
    }
};
// T.C: O(n^2) ~ O(n^2)
// S.C: O(n)
