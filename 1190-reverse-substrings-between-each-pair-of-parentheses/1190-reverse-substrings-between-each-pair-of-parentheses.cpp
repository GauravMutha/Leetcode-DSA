class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string res;
        for(auto c:s){
            if(c=='(') st.push(res.length());
            else if(c==')'){
                reverse(res.begin()+st.top(),res.end());
                st.pop();
            }
            else res+=c;
        }
        return res;
    }
};
//MORE CONCISE Brute Force
//1 pass
//TC-->O(n^2)
//SC-->O(n)