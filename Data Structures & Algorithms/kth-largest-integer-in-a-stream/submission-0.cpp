class KthLargest {
    // min heap
    priority_queue<int,vector<int>,greater<int>>pq;
    int kl;
public:
    KthLargest(int k, vector<int>& nums) {
        kl=k;
        for(int num:nums) {
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>kl) pq.pop();
        return pq.top();
    }
};
