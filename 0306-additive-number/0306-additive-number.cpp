// Mixture of 842 and 1849
class Solution {
public:
    bool helper(int ind,vector<long long> &ds,string& numStr){
        if(ind==numStr.size() && ds.size()>2)
            return true;
        for(int i=1;i+ind<=numStr.size();i++){
            string temp=numStr.substr(ind,i);
            if(temp.size()>1 && temp[0]=='0') return false;
            long long num=stoll(temp);
            if(num>99999999999999999) return false;
            if((ds.size()<2) || ((long long)ds[ds.size()-1]+(long long)ds[ds.size()-2]==num)){
                ds.push_back(num);
                if(helper(ind+i,ds,numStr)) return true;
                ds.pop_back();
            }
            else if(((long long)ds[ds.size()-1]+(long long)ds[ds.size()-2])<num) break;
                
        }
        return false;
    }
    bool isAdditiveNumber(string numStr) {
        vector<long long>ds;
        return helper(0,ds,numStr);
    }
};