class Solution {
public:
    int mod=1000000007;
    long long power(int x, int n){
        if(n==0) return 1;
        
        long long ans=power(x,n/2);
        ans*=ans;
        ans%=mod;
        
        if(n%2){
            ans*=x;
            ans%=mod;
        }
        
        return ans;
    }
    long long fact(int n){
        long long ans=1;
        
        for(int i=1;i<=n;i++)
            ans*=i, ans%=mod;
        
        return ans;
    }
    long long nCr(int n, int r){
        long long numer=fact(n);
        long long denom=(fact(r)*fact(n-r))%mod;
        
        return (numer*power(denom,mod-2))%mod;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        long long ans=1;
        vector<int>hash(26,0);
        priority_queue<int>pq;
        
        for(auto c : s) hash[c-'a']++;
        for(auto f : hash) if(f>0) pq.push(f);
        
        if(pq.size()<k) return 0; //not possible to make k-subsequence
        
        while(k>0){
            int freq=pq.top() , countFreq=0;
            while(pq.size() && pq.top()==freq) countFreq++ , pq.pop();
            
            if(countFreq<=k){
                k-=countFreq;
                ans*=power(freq,countFreq);
                ans%=mod;
            }
            else{
                ans*=power(freq,k);
                ans%=mod;
                
                ans*=nCr(countFreq,k);
                ans%=mod;
                
                break;
            }
        }
        
        return (int)ans;
    }
};