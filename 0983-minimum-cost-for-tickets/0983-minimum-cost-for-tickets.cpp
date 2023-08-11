class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int lastDay=days.back();
        set<int>st(days.begin(),days.end());
        vector<int>dp(lastDay+1,0);
        
        for(int i=1;i<=lastDay;i++){
            if(st.find(i)==st.end()) dp[i]=dp[i-1];
            else{
                int cost_one=costs[0]+dp[i-1];
                int cost_week=costs[1]+dp[max(0,i-7)];
                int cost_month=costs[2]+dp[max(0,i-30)];
                
                dp[i]=min({cost_one,cost_week,cost_month});
            }
        }
        
        return dp[lastDay];
    }
};