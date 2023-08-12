//Tabulation 2.0
class Solution {
public:
    static bool cmp(const vector<int> & v1, const vector<int> & v2) {
        return v1[0] < v2[0];
    }
    
    bool check(int i,int pre,vector<vector<int>>& pairs){
        return (pairs[pre][1]<pairs[i][0]);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        vector<int>dp(pairs.size(),1);
        sort(pairs.begin(),pairs.end(),cmp);
        int res=1;
        
        for(int i=0;i<pairs.size();i++){
            
            for(int pre=0;pre<i;pre++){
                if(check(i,pre,pairs)==false) continue;
                dp[i]=max(res,1+dp[pre]);
            }
            
            res=max(dp[i],res);
        }
        return res;
    }
};