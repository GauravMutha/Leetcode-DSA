class Solution {
public:
    long long maximumSumOfHeights(vector<int>& mh) {
        
        long long res=0LL;
        int n=mh.size();
        
        for(int i=0;i<n;i++){
            
            int lpeak,gpeak; //local peak , global peak
            lpeak=gpeak=mh[i];
            long long sum=(long long)mh[i];
            
            //left side of peak
            for(int j=i-1;j>=0;j--){
                int curr=mh[j];
                if(curr>lpeak) curr=lpeak;
                else if(curr<lpeak) lpeak=curr;
                
                sum+=(long long)curr;
            }
            
            lpeak=gpeak;
            //right side of peak
            for(int j=i+1;j<n;j++){
                int curr=mh[j];
                if(curr>lpeak) curr=lpeak;
                else if(curr<lpeak) lpeak=curr;
                
                sum+=(long long)curr;
            }
            cout<<sum<<endl;
            res=max(sum,res);
        }
        return res;
    }
};