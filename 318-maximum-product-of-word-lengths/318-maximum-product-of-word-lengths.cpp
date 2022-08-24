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
            for(int j=0;j<words.size();j++){
                val1=dp[i];
                val2=dp[j];
                if(!common(val1,val2)){
                    prod=(words[i].length())*(words[j].length());
                    maxlen=max(maxlen,prod);
                }
            }
        }
        return maxlen;
    }
    
    bool common(int a , int b){
        for(int i=0;i<26;i++){
            int mask=1<<i;
            if((mask&a)==(mask&b)){
                if((mask&a)!=0)return true;
            }
        }
        return false;    
    }
};