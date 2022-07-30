class Solution {
public:
    vector<int> countBits(int n) {
        //TC----->O(n)
        
        vector<int>ans;
        
        ans.push_back(0);
        if(n<1)return ans;
        
        for(int i=1;i<=n;i++){
            if(i%2==0)ans.push_back(ans[i/2]);
            else ans.push_back(ans[i/2]+1);
        }
        
        return ans;
    }
};