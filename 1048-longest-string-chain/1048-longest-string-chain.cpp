//Memoization

class Solution {
public:
    bool check(string &str1 , string &str2){
        if(str2.size() != (str1.size()+1) ) return false;
        
        int i=0,j=0,diff=0;
        while(j<str2.size() && i<str1.size()){
            if(str1[i]==str2[j]) i++ , j++;
            else{
                diff++;
                if(diff>1) return false;
                j++;
            }
        }
        
        return true;
        
    }
    int helper(int ind,int preInd,vector<string>& words,vector<vector<int>>& dp){
        
        if(ind>=words.size()) return 0;
        
        if(dp[ind][preInd+1]!=-1) return dp[ind][preInd+1];
        
        int pick=0;
        
        if(preInd==-1 || check(words[preInd],words[ind])) 
            pick=1+helper(ind+1,ind,words,dp);
        int notPick=helper(ind+1,preInd,words,dp);
        
        return dp[ind][preInd+1]=max(pick,notPick);
    }
    int longestStrChain(vector<string>& words) {
        
        int n=words.size(),res=1;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        //writing cmp function to sort the words in increasing order of sizes
        auto cmp = [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
        };
        sort(words.begin(),words.end(),cmp);
        
        
        return helper(0,-1,words,dp);
        
    }
};