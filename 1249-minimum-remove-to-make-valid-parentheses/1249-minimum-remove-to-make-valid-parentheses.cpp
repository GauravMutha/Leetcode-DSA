class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>st;
        vector<int>vec;
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push('(') ,vec.push_back(i);
            else if(!st.empty() && s[i]==')') st.pop(),vec.pop_back();
            else if(st.empty() && s[i]==')') vec.push_back(i);
        }
        if(vec.empty()) return s;
        for(int i=0,k=0;i<s.size();i++){
            if(k<vec.size() && i==vec[k]) k++;
            else res+=s[i];
        }
        return res;
    }
};