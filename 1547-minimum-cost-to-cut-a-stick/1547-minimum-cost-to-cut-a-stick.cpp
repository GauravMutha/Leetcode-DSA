//Memoization

class Solution {
public:
    int helper(int i,int j,vector<int>& cuts,vector<vector<int>>& dp){
        
        if(i>j) return 0;
        
        int minCost=1e9;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        for(int ind=i;ind<=j;ind++){
            
            int cost=cuts[j+1]-cuts[i-1]+helper(i,ind-1,cuts,dp)+helper(ind+1,j,cuts,dp);
            
            minCost=min(minCost,cost);
        }
        
        return dp[i][j]=minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        
        int lastCutIndx=cuts.size();
        
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>>dp(lastCutIndx+1,vector<int>(lastCutIndx+1,-1));
        
        return helper(1,lastCutIndx,cuts,dp);
    }
};