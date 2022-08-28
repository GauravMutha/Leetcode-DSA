class Solution {
public:
    int concatenatedBinary(int n) {
        long res=1; int lim=0,mod=1000000007;
        for(int i=2;i<=n;i++){
            lim=log2(i)+1;
            res= (res<<lim)%mod;
            res+=i%mod;    
        }
        return (res);
    }
};