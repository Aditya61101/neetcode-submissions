class MinStack {
    stack<int>main, minStore;
public:
    MinStack() {}
    
    void push(int val) {
        main.push(val);
        if(minStore.empty() || minStore.top() >= val) minStore.push(val);
    }
    
    void pop() {
        if(minStore.top()==main.top()) minStore.pop();
        main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return minStore.top();
    }
};
