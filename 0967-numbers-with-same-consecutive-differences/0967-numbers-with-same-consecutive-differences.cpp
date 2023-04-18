//Backtracking
class Solution {
private:
    vector<int>ans;
public:
    void helper(string &ds, int len,int k){
        if(ds.size()==len){
            ans.push_back(stoi(ds));
            return;
        }
        for(char i='0';i<='9';i++){
            if(ds.size()==0 && i=='0') continue;
            if(ds.size()==0 || abs(ds.back()-i)==k){
                ds.push_back(i);
                helper(ds,len,k);
                ds.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string ds;
        helper(ds,n,k);
        
        return ans;
    }
};