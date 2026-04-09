class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        // counting sort
        int m = *max_element(people.begin(), people.end());
        vector<int>freq(m+1);
        for(int p:people) {
            freq[p]+=1;
        }
        // here w represents weight
        int idx=0, w=1;
        while(idx<n) {
            // we skip weights with no frequency since no person has this weight
            while(freq[w]==0) w+=1;
            // the first point where the above loop breaks is the point 
            // where we have found a weight with non-zero frequency
            people[idx++] = w;
            // decrease its frequency
            freq[w]-=1;
        }
        // two pointers starts here
        int i=0,j=n-1;
        int boats=0;
        while(i<=j) {
            if(people[i]+people[j]<=limit) {
                i+=1; 
            }
            boats+=1;
            // moving person with higher weight since for future 
            // matching we may have sum of weight<=limit
            j-=1;
        }
        return boats;
    }
};