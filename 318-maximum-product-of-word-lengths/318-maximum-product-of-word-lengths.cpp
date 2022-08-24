class Solution {
public:
    int hash(string s){
        int hash=0;
        for(auto elem:s){
            hash|=(1<<(elem-'a'));
        }
        return hash;
    }
    
    int maxProduct(vector<string>& words) {
        vector<int>dp(words.size(),0);
        int val1=0,val2=0,maxlen=0,prod=0;
        for(int i=0;i<words.size();i++)
            dp[i]=hash(words[i]);
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                val1=dp[i];
                val2=dp[j];
                if((val1&val2)==0 && words[i].length()*words[j].length()>maxlen){
                    maxlen=words[i].length()*words[j].length();
                }
            }
        }
        return maxlen;
    }
};