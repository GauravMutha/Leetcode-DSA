//Backtracking
//Similar to 93.Restore IP address
class Solution {
public:

    bool helper(int ind,vector<long long>& ds,string &numStr){
        if(ind==numStr.size()){
            if((ds.size()>2) && ((ds[ds.size()-3]+ds[ds.size()-2])==ds[ds.size()-1])){
                return true;
            }
        }
        for(int i=ind;i<numStr.size();i++){
            string temp=numStr.substr(ind,i-ind+1);
            long long num=stoll(temp);
            if((temp.size()>1) && (temp[0]=='0')) break;
            if(num>INT_MAX) break;
            if((ds.size()<2) || ((ds[ds.size()-1]+ds[ds.size()-2])==num)){
                ds.push_back(num);
                if(helper(i+1,ds,numStr)) return true;
                ds.pop_back();
            }
            else if((ds[ds.size()-1]+ds[ds.size()-2])>num) continue;
            else if((ds[ds.size()-1]+ds[ds.size()-2])<num) break;
                
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string numStr) {
        vector<int>ans;
        vector<long long>ds;
        helper(0,ds,numStr);
        for(auto e:ds){
            ans.push_back((int)e);
        }
        return ans;
    }
};