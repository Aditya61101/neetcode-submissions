class Solution {
    vector<int> mergeSortedArrays(vector<int>&left, vector<int>&right) {
        int ls = left.size(), rs = right.size();

        vector<int>ans;
        int i=0, j=0;
        while(i<ls && j<rs) {
            if(left[i]<=right[j]) {
                ans.push_back(left[i]);
                i+=1;
            } else {
                ans.push_back(right[j]);
                j+=1;
            }
        }

        while(i<ls) {
            ans.push_back(left[i]);
            i+=1;
        }

        while(j<rs) {
            ans.push_back(right[j]);
            j+=1;
        }
        return ans;
    }
    vector<int> mergeSort(int l, int r, vector<int>& nums) {
        if(l==r) return {nums[l]};
        int mid = (l+r)/2;
        vector<int> left = mergeSort(l, mid, nums);
        vector<int> right = mergeSort(mid+1, r, nums);
        return mergeSortedArrays(left, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0, n-1, nums);
    }
};