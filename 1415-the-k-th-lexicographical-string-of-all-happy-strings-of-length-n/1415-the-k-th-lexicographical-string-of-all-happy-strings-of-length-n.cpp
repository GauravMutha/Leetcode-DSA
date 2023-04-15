//Re//
//Permutation

class Solution {
private:
    string ans="";
    int count=0;
public:
    void helper(string &ds, int len , int k){
        if(ans.size()!=0) return;
        if(ds.size()==len){
            count++;
            if(count==k) ans=ds;
            return;
        }
        for(char ch='a';ch<='c' && ans.size()==0;ch++){
            if(ds.size()>0 && ch==ds.back()) continue;
            ds.push_back(ch);
            helper(ds,len,k);
            ds.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string ds;
        helper(ds,n,k);
        
        return ans;
    }
};