class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        using pii = pair<int, int>;
        int n = profits.size();
        priority_queue<pii, vector<pii>, greater<pii>> pool;
        priority_queue<int> candidates;
        for (int i = 0; i < n; i++) {
            pool.emplace(capital[i], profits[i]);
        }

        while (k--) {
            while (!pool.empty() && w >= pool.top().first) {
                auto [c, p] = pool.top();
                pool.pop();
                candidates.emplace(p);
            }
            if (!candidates.empty()) {
                w += candidates.top();
                candidates.pop();
            } else
                break;
        }
        return w;
    }
};