class Solution {
public:
    bool check(string &str1 , string &str2){
        if(str1.size()!=str2.size()) return false;
        int i=0,j=0,diff=0;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]) diff++;
            if(diff>1) return false;
        }
        
        return true;
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        
        int ind=0,maxlen=1;
        vector<int>dp(n,1),hash(n,-1);
        vector<string>res;
        
        for(int curr=0;curr<n;curr++){
            for(int prev=0;prev<curr;prev++){
                if((groups[prev]==groups[curr]) || (check(words[prev],words[curr])==false)) continue;
                if((dp[prev]+1)>dp[curr]) dp[curr]=dp[prev]+1, hash[curr]=prev;
            }
            if(dp[curr]>maxlen) maxlen=dp[curr],ind=curr;
        }
        
        if(maxlen<=0) return {};
        
        for(int i=0;i<hash.size();i++) cout<<hash[i]<<" ";
        int j=ind;
        while(j>=0){
            res.push_back(words[j]);
            j=hash[j];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};