class FreqStack {
    unordered_map<int,int>elementFreqMap;
    unordered_map<int,vector<int>>freqElementsMap;
    int maxFreq;
public:
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int val) {
        elementFreqMap[val]+=1;
        // if we get a frequency which is even greater than current maxFreq
        // then we have a new frequency
        if(maxFreq < elementFreqMap[val]) {
            maxFreq=elementFreqMap[val];
            freqElementsMap[elementFreqMap[val]] = vector<int>();
        }
        freqElementsMap[elementFreqMap[val]].push_back(val);
    }
    
    int pop() {
        int n = freqElementsMap[maxFreq].size();
        int val = freqElementsMap[maxFreq][n-1];
        freqElementsMap[maxFreq].pop_back();
        elementFreqMap[val]-=1;
        // if after removing the element for this maxFreq
        // theres no element left, then maxFreq should decrease by 1
        if(freqElementsMap[maxFreq].size()==0) {
            freqElementsMap.erase(maxFreq);
            maxFreq-=1;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */