//Brute force
//Backtracking
class Solution {
private:
    int ans=0;
public:
    void helper(int ind,string& givenStr ,unordered_set<string>allSubstr){
        if(ind==givenStr.size()){
            ans=max((int)allSubstr.size(),ans);
            return;
        }
        string subStr="";
        for(int i=ind;i<givenStr.size();i++){
            subStr.push_back(givenStr[i]);
            if(allSubstr.count(subStr)==0){
                allSubstr.insert(subStr);
                helper(i+1,givenStr,allSubstr);
                allSubstr.erase(subStr);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        helper(0,s,st);
        
        return ans;
    }
};