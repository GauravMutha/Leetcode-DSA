//Tabulation
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        int n=stones.size();
        vector<vector<bool>>dp(n,vector<bool>(n+1,false));
        dp[0][1]=true;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int reqJump=stones[i]-stones[j];
                if(reqJump>n || !dp[j][reqJump]) continue;
                //we did not hit the continue statement an i is the last element
                if(i==n-1) return true;
                
                dp[i][reqJump]=true;
                if(reqJump-1 >=0) dp[i][reqJump-1]=true;
                if(reqJump+1 < n) dp[i][reqJump+1]=true;
            }
        }
        
        return false;
    }
};