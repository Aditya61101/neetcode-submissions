class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0, count=1, n=chars.size();
        for(int i=1;i<=n;i++){
            if(i==n||chars[i]!=chars[i-1]){
                chars[idx++]=chars[i-1];
                if(count>1){
                    string ch=to_string(count);
                    for(char c:ch){
                        chars[idx++]=c;
                    }
                }
                count=1;
            } else {
                count++;
            }
        }
        return idx;
    }
};