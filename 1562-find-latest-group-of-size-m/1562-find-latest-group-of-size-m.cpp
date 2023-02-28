//Binary search
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        if(n==m) return n;
        
        set<pair<int,int>>s;
        s.insert({1,n});
        
        for(int i=n-1;i>=0 && !s.empty() ;i--){
            
            auto it=s.upper_bound({arr[i],INT_MAX});
            it--;
            int L=it->first ,R=it->second;
            s.erase(it);
            int len1=arr[i]-L , len2=R-arr[i];
            
            if(len1==m || len2==m) return i;
            
            if(len1>0) s.insert({L,arr[i]-1});
            if(len2>0) s.insert({arr[i]+1,R});
        }
        
        return -1;
    }
};