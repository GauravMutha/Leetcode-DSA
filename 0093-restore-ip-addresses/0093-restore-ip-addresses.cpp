//Backtracking
class Solution {
private:
    vector<string>ans;
public:
    bool validate(string sample){
        if(sample.size()>3 || sample.size()==0) return false;
        if(sample.size()>1 && sample[0]=='0') return false;
        if(sample.size()==3 && stoi(sample)>255) return false;
        
        return true;
    }
    void helper(int ind,string ds,int dots,string &s){
        if(dots==3){
            if(validate(s.substr(ind))) 
                ans.push_back(ds+s.substr(ind));
            return;
        }
        for(int i=ind;i<min(ind+3,(int)s.size());i++){
            if(validate(s.substr(ind,i-ind+1))==false) continue;
            ds.push_back(s[i]);
            ds.push_back('.');
            helper(i+1,ds,dots+1,s);
            ds.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string ds="";
        int dots=0;
        helper(0,ds,dots,s);
        
        return ans;
    }
};
