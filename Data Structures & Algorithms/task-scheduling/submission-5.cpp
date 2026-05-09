class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26);
        for(char c:tasks) freq[c-'A']+=1;
        
        int max_freq = *max_element(freq.begin(),freq.end());
        
        int freq_elements = 0;
        for(int f:freq) if(f==max_freq) freq_elements+=1;
        
        int time = max((int)tasks.size(), (n+1)*(max_freq-1)+freq_elements);
        return time;
    }
};
