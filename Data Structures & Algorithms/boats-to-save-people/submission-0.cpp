class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n=people.size();
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