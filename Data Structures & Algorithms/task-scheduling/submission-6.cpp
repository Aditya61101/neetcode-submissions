class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26);
        for(char c:tasks) freq[c-'A']+=1;
        
        int max_freq = *max_element(freq.begin(),freq.end());
        
        int freq_elements = 0;
        for(int f:freq) if(f==max_freq) freq_elements+=1;
        //A:4,B:4,n:2; (AB _)AB _AB _AB
        // first 3 As create gaps each of length n+1 after them
        // last A doesn't need any trailing gap, so max_freq-1
        // multiply by n+1 since for each max_freq-1 As, we have n+1 slots
        // add with freq_elements, since multiple tasks can share highest frequency.
        int time = max((int)tasks.size(), (n+1)*(max_freq-1)+freq_elements);
        return time;
    }
};
