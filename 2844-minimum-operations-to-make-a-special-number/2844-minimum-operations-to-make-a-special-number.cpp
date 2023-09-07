//DP Memoization
class Solution {
public:
    int dp[101][25];
    int helper(int ind,int num,string &s){
        
        if(ind==s.size()) return (num%25==0)? 0 : 1e9;
        if(dp[ind][num]!=-1) return dp[ind][num];
        
        int dig=s[ind]-'0';
        
        int pick=helper(ind+1,(num*10+dig)%25,s);
        int notPick=1+helper(ind+1,num,s);
        
        return dp[ind][num]=min(pick,notPick);
        
    }
    int minimumOperations(string s) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,s);    
    }
};