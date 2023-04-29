//Backtracking
// Similar to 842 split array into fibonacci sequence
class Solution {
public:
    bool helper(int ind,vector<long long> &ds,string& numStr){
        if(ind==numStr.size() && ds.size()>1)
            return true;
        for(int i=1;i+ind<=numStr.size();i++){
            string temp=numStr.substr(ind,i);
            long long num=stoll(temp);
            if(num>99999999999) return false;
            if(ds.size()==0 || (long long)ds.back()==(num+1)){
                ds.push_back(num);
                if(helper(ind+i,ds,numStr)) return true;
                ds.pop_back();
            }
        }
        return false;
    }
    bool splitString(string numStr) {
        vector<long long>ds;
        return helper(0,ds,numStr);
    }
};