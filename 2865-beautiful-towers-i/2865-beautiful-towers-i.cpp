class Solution {
public:
    long long maximumSumOfHeights(vector<int>& mh) {
        int n=mh.size();
        long long i=0, res=0;
        stack<int>s1,s2;
        vector<long long>pref(n,mh[0]),suff(n,mh[n-1]);
        vector<int>nsl(n,-1),nsr(n,-1);
        
        //next smaller to left & filling prefix
        s1.push(0);
        for(i=1;i<n;i++){
            
            while(s1.size() && mh[s1.top()]>mh[i]) s1.pop();
            if(s1.size()) nsl[i]=s1.top();
            s1.push(i);
            
            if(nsl[i]==-1) pref[i]=(i+1)*mh[i];
            else pref[i]=pref[nsl[i]]+(i-nsl[i])*mh[i];
        }
        //next smaller to left & filling prefix
        s2.push(n-1);
        for(i=n-2;i>=0;i--){
            
            while(s2.size() && mh[s2.top()]>mh[i]) s2.pop();
            if(s2.size()) nsr[i]=s2.top();
            s2.push(i);
            
            if(nsr[i]==-1) suff[i]=(n-i)*mh[i];
            else suff[i]=suff[nsr[i]]+(nsr[i]-i)*mh[i];
        }
        
        for(int i=0;i<n;i++){
            long long sum=(pref[i] + suff[i] - mh[i]);
            res=max(res,sum);
        }
        
        return res;
    }
};