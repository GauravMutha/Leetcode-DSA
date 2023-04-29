//Backtracking
//Similar to 93.Restore IP address
class Solution {
public:

    bool helper(int ind,vector<int>& ds,string &numStr){
        if(ind==numStr.size() && ds.size()>2){
            return true;
        }
        
        for(int i=1;i<=10 && ind+i<=numStr.size() ;i++){
            string temp=numStr.substr(ind,i);
            long long num=stoll(temp);
            if((temp.size()>1) && (temp[0]=='0')) break;
            if(num>INT_MAX) break;
            if((ds.size()<2) || ((long long)ds[ds.size()-1]+(long long)ds[ds.size()-2]==num)){
                ds.push_back(num);
                if(helper(ind+i,ds,numStr)) return true;
                ds.pop_back();
            }
            else if(((long long)ds[ds.size()-1]+(long long)ds[ds.size()-2])<num) break;
                
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string numStr) {
        vector<int>ds;
        helper(0,ds,numStr);
        return ds;
    }
};