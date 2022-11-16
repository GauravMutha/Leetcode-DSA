class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                reverse(s.begin()+st.top()+1,s.begin()+i);
                st.pop();
            }
        }
        for(int i=0;i<s.size();i++)
            if(isalpha(s[i])) res+=s[i];
        return res;
    }
};

//Brute Force , 2 pass
//TC-->O(n^2)
//SC-->O(n)