//Sliding window
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size(),maxLen=INT_MIN,l=0,r=0,cost=0;
        for(;r<n;r++){
            cost+=abs(s[r]-t[r]);
            while(cost>maxCost) cost-=abs(s[l]-t[l]) , l++;
             maxLen=max(maxLen,r-l+1);
        }
        
        return maxLen;
    }
};