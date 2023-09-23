class Solution {
public:
    bool check(string &str1 , string &str2){
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
        int n=words.size(),res=1;
        
        vector<int>dp(n,1);
        
        auto cmp=[](const string &a , const string &b){
            return a.length()<b.length();
        };
        
        sort(words.begin(),words.end(),cmp);
        
        for(int ind=0;ind<n;ind++){
            for(int pre=0;pre<ind;pre++){
                if(words[ind].size()!=(words[pre].size()+1)) continue;
                if(check(words[pre],words[ind]))
                    dp[ind]=max(1+dp[pre],dp[ind]);
            }
            res=max(res,dp[ind]);
        }
        
        return res;
    }
};