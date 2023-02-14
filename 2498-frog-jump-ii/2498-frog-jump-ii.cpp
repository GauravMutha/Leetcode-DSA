//TC-->O(N)
//SC-->O(1)
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size() , ans=INT_MIN;
        if(stones.size()==2) return (stones[1]-stones[0]);
        
        for(int i=0;i<n;i++){
            if(i+2<n) ans=max(ans,abs(stones[i]-stones[i+2]));
        }
        return ans;
    }
};