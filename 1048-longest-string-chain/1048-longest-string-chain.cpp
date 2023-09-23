//Memo
class Solution {
public:
    bool check(string &s1 , string &s2){
        
        int i=0,j=0,diff=0,n1=s1.length(),n2=s2.size();
        
        if(n2!=(n1+1)) return false;
        
        while(i<n1 && j<n2){
            if(s1[i]==s2[j]) i++,j++;
            else{
                diff++;
                if(diff>1) return false;
                j++;
            }
        }
        return true;
    }
    int helper(int ind, int pre,vector<string>& words,vector<vector<int>>& dp){
        
        if(ind>=words.size()) return 0;
        
        if(dp[ind][pre+1]!=-1) return dp[ind][pre+1];
        
        int pick=0;
        if(pre==-1 || check(words[pre],words[ind]))
            pick=1+helper(ind+1,ind,words,dp);
        int notPick=helper(ind+1,pre,words,dp);
    
        return dp[ind][pre+1]=max(pick,notPick);
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        auto cmp=[](const string &a , const string &b){
            return a.length()<b.length();
        };
        
        sort(words.begin(),words.end(),cmp);
        
        return helper(0,-1,words,dp);
    
    }
};