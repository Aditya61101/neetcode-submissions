class MinStack {
    // stores difference between incoming val and min val.
    stack<long> diff;
    long minVal = INT_MAX;

   public:
    MinStack() {}

    void push(int val) {
        if (diff.empty()) {
            diff.push(0);
            minVal = val;
        } else {
            diff.push(val - minVal);
            if (val < minVal) minVal = val;
        }
    }

    void pop() {
        long top = diff.top();
        // int currMin = minVal;
        diff.pop();
        if (top < 0) minVal = minVal - top;

        // if(top<=0) return currMin;
        // return top+currMin;
    }

    int top() {
        if (diff.top() <= 0) return (int)minVal;
        return diff.top() + minVal;
    }

    int getMin() { return (int)minVal; }
};
