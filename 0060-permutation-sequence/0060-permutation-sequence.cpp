class Solution {
private:
    vector<int>factorial={1,1,2,6,24,120,720,5040,40320,362880};
    vector<char>nums;
    string ans="";
public:
    void solve(int n,int k){
        
        if(n==1){
            ans.push_back(nums.back());
            return;
        }
        int ind=k/factorial[n-1];
        if(k%factorial[n-1]==0) ind--;
        
        ans.push_back(nums[ind]);
        nums.erase(nums.begin()+ind);
        
        k-=(factorial[n-1]*ind);
        
        solve(n-1,k);
    }
    
    string getPermutation(int n, int k) {
        for(int i=1;i<=n;i++) nums.push_back(i+'0');
        solve(n,k);
        return ans;
    }
};