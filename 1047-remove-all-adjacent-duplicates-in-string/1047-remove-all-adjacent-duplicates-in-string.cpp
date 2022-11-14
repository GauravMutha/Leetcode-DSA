class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(res.size()!=0 && res.back()==s[i])
                res.pop_back();
            else res.push_back(s[i]);
        }
        
        return res;
    }
};

//O(1) space complexity --> we make our string res behave like a stack whichw e eventually return hence making the constant SC.