class Solution {
private:
    vector<vector<int>>ans;
public:
    void helper(int i,vector<int>& ds,int target,int szLimit){
        if(target==0 && ds.size()==szLimit){ //or we can write sum==i
            ans.push_back(ds);
            return;
        }
        if(ds.size()>szLimit || i>9) return;
        ds.push_back(i);
        helper(i+1,ds,target-i,szLimit);
        
        ds.pop_back();
        helper(i+1,ds,target,szLimit);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //k is size limit of ds
        //n is the target
        int sum=1;
        int i=1;
        vector<int>ds;
        helper(i,ds,n,k);
        
        return ans;
    }
};