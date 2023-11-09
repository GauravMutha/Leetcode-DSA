class Solution {
public:
    int countHomogenous(string s) {
        int mod=1e9+7;
        long long res=0;
        for(long long i=0;i<s.size();){
            char c=s[i];
            long long j=i;
            while(j<s.size() && s[j]==c) j++;
            
            res+=(((j-i)*(j-i+1))%mod/2)%mod;
            
            i=j;
        }
        
        return (int)(res%mod);
    }
};