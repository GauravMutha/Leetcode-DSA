//Backtracking
class Solution {
private:
    vector<string>ans;
    unordered_map<char,string>m;
public:
    void helper(int it,string& ds,string& digits){
        if(it>=digits.size()){
            ans.push_back(ds);
        }
        for(int i=0;i<m[digits[it]].size();i++){
            ds.push_back(m[digits[it]][i]);
            helper(it+1,ds,digits);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        for(auto &ch : digits){
            string letters="";
            int number=ch-'0' , letterCnt=3;
            char startChar=(number-2)*3+'a';
            if(number==7) letterCnt++;
            else if(number==8) startChar++;
            else if(number==9) letterCnt++ , startChar++;
            for(int i=1;i<=letterCnt;i++) letters.push_back(startChar++);
            m[ch]=letters;
        }
        string ds="";
        helper(0,ds,digits);
        
        return ans;
    }
};