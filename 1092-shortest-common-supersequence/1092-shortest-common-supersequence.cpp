/*Its similar to DP-26 i.e. printing longest
common subsequence.Go to DP-26*/

//Tabulation
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        string res="";
        int n=str1.size() , m=str2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                int count=0;
                if(str1[ind1-1]==str2[ind2-1]) count=1+dp[ind1-1][ind2-1];
                else count= max(dp[ind1-1][ind2] , dp[ind1][ind2-1]);

                dp[ind1][ind2]=count;
            }
        }
        int i=n,j=m;
        while(i>0 && j>0){

            if(str1[i-1]==str2[j-1]){
                res.push_back(str1[i-1]);
                i--;
                j--;	
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                res.push_back(str1[i-1]);
                i--;
            }
            else{
                res.push_back(str2[j-1]);
                j--;
            }
        }
        
        
        while(i>0) res.push_back(str1[i-1]) , i--;
        while(j>0) res.push_back(str2[j-1]) , j--;
        
        reverse(res.begin(),res.end());
        
        
        return res;
    }
};