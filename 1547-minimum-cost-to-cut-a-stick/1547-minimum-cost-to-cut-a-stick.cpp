//Tabulation

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        int lastCutIndx=cuts.size();
        
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        
        vector<vector<int>>dp(lastCutIndx+2,vector<int>(lastCutIndx+2,0));
        
        for(int i=lastCutIndx;i>=1;i--){
            for(int j=i;j<=lastCutIndx;j++){
                int minCost=1e9;
                for(int ind=i;ind<=j;ind++){

                    int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];

                    minCost=min(minCost,cost);
                }

                dp[i][j]=minCost;
            }
        }
        
        return dp[1][lastCutIndx];
        
    }
};