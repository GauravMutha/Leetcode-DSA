class Solution {
private:
    vector<vector<string>>res;
    void helper(int ind,vector<string>& ds,string &s){
        if(ind==s.size()){
            res.push_back(ds);
        }
        
        for(int i=ind;i<s.size();i++){
            if(palinCheck(s,ind,i)==false) continue;
            ds.push_back(s.substr(ind,i-ind+1));
            helper(i+1,ds,s);
            ds.pop_back();
        }
    }
    bool palinCheck(string &s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        helper(0,ds,s);
        
        return res;
    }
};