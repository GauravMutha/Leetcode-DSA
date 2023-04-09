//RE//

class Solution {
private:
    vector<vector<int>> ans;
public:
    void helper(int i,int n,int k,vector<int>& ds){
        if(k>(n-i+1)) return;
        if(k==0){ //or we could write k==0
            ans.push_back(ds);
            return;
        }
        if(i>n) return;
        ds.push_back(i);
        helper(i+1,n,k-1,ds);
        ds.pop_back();
        helper(i+1,n,k,ds);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ds;
        helper(1,n,k,ds);
        return ans;
    }
};