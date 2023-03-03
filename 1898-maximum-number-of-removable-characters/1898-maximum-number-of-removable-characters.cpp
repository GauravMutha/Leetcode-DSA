class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& rem) {
        vector<int>m(s.size(),INT_MAX);
        int ans=0;
        for(int i=0;i<rem.size();i++){
            m[rem[i]]=i;
        }
        
        int low=0,high=rem.size();
        while(low<=high){
            int mid=low+(high-low)/2,j=0;
            
            for(int i=0;i<s.size() && j<p.size();i++){
                if(m[i]>(mid-1) && s[i]==p[j]) j++;
            }
            if(j==p.size()) low=mid+1 , ans=mid;
            else high=mid-1;
        }
        
        return ans;
    }
};