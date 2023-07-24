//Only 1 Array Space optimisation
//We had to use double as some testcases were giving overflow issues
class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n=s.size() , m=t.size();
        
        vector<double>dp(m+1,0);
        
        //initialising the dp
        dp[0]=1;
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=m;ind2>=1;ind2--){
                
                double count=0.0;
                
                if(s[ind1-1]==t[ind2-1]) count=dp[ind2-1]+dp[ind2];
                else count=dp[ind2];
                
                dp[ind2]=count;
                
            }
        }
        
        return (int)dp[m];
    }
};