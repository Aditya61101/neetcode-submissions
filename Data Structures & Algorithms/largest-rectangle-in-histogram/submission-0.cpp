class Solution {
    void nsl(vector<int>& h, vector<int>& idxs) {
        stack<int> st;  // store indexes
        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }

            if (st.empty())
                idxs[i] = -1;
            else
                idxs[i] = st.top();
            st.push(i);
        }
    }
    void nsr(vector<int>& h, vector<int>& idxs) {
        stack<int> st;  // stores indexes
        int n = h.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && h[st.top()] >= h[i]) {
                st.pop();
            }

            if (st.empty())
                idxs[i] = n;
            else
                idxs[i] = st.top();
            st.push(i);
        }
    }

   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> lIdxs(n);
        nsl(heights, lIdxs);

        vector<int> rIdxs(n);
        nsr(heights, rIdxs);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int larea = (i - lIdxs[i]) * heights[i];
            int rarea = (rIdxs[i] - i) * heights[i];
            int area = larea + rarea - heights[i];

            maxArea = max({maxArea, area});
        }
        return maxArea;
    }
};
