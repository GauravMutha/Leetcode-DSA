//Tabulation

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
    
    int longestStrChain(vector<string>& words) {
        
        int n=words.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        //writing cmp function to sort the words in increasing order of sizes
        auto cmp = [](const std::string& a, const std::string& b) {
            return a.size() < b.size();
        };
        sort(words.begin(),words.end(),cmp);
        
        
        for(int ind=n-1;ind>=0;ind--){
            for(int preInd=ind-1;preInd>=-1;preInd--){
                
                int pick=0;
                if(preInd==-1 || check(words[preInd],words[ind])) 
                    pick=1+dp[ind+1][ind+1];
                int notPick=dp[ind+1][preInd+1];
                
                dp[ind][preInd+1]=max(pick,notPick);
            }
        }
        
        return dp[0][0];
        
    }
};