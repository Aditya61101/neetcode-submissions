class StockSpanner {
    // {index, value}
    stack<pair<int,int>>st;
    int cnt = 1;
public:
    StockSpanner() {}
    
    int next(int price) {
        while(st.size() && price >= st.top().second) {
            st.pop();
        }
        int days=cnt;
        if(st.size()) days = cnt-st.top().first;
        st.push({cnt,price});
        cnt+=1;
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */