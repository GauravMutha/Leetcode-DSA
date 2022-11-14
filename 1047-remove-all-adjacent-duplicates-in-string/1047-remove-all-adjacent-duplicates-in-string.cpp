class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top()==s[i])
                st.pop();
            else st.push(s[i]);
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(begin(res),end(res));
        return res;
    }
};

//O(n) space complexity