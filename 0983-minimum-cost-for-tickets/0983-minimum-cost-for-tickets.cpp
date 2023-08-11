class Solution {
public:
    int helper(int ind,vector<int>& dp,vector<int>& days,vector<int>& costs)
    {
        if(ind>=days.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        //one day pass
        int cost_one=costs[0]+ helper(ind+1,dp,days,costs);
        
        int i;
        //week day pass
        for(i=ind;i<days.size() && days[i]<(days[ind]+7);i++);
        int cost_week=costs[1]+helper(i,dp,days,costs);
        
        //month day pass
        for(i=ind;i<days.size() && days[i]<(days[ind]+30);i++);
        int cost_month=costs[2]+helper(i,dp,days,costs);
        
        return dp[ind]=min({cost_one,cost_week,cost_month});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(367,-1);
        return helper(0,dp,days,costs);
    }
};