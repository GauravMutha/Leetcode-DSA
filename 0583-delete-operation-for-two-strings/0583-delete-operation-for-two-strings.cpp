/*We only need to do just one operation
on whatever result we get from 1143.longest 
common subsequence,that's all*/

//Space optimisation
class Solution {
public:
    //below function is as it is from 1143.Longest common subsequecnce
    int longestCommonSubsequence(string& text1, string& text2) {
        
        int n1=text1.size() , n2=text2.size();
        vector<int>dp(n2+1,0);
        
        for(int ind1=1;ind1<=n1;ind1++){
            vector<int>tempDP(n2+1,0);
            for(int ind2=1;ind2<=n2;ind2++){
                int count=0;
                if(text1[ind1-1]==text2[ind2-1]) count=1+dp[ind2-1];
                else count= max(dp[ind2] , tempDP[ind2-1]);
                
                tempDP[ind2]=count;
            }
            dp=move(tempDP);
        }
        
        
        
        return dp[n2];
    }
    
    int minDistance(string word1, string word2) {
        int lcsLength=longestCommonSubsequence(word1,word2);
        
        int totalLength=word1.size()+word2.size();
        
        return totalLength-2*lcsLength;
    }
};