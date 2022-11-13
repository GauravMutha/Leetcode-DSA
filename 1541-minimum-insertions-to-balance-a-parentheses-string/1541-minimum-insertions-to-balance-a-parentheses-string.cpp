class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(s[i]);
            else{
                if((i+1)<s.size() && s[i+1]==')'){
                    if(st.empty()) ans++;
                    else st.pop();
                    i++;
                }
                else if((i+1)>=s.size() || s[i+1]=='('){
                    if(st.empty()) ans+=2;
                    else ans++,st.pop();
                }
            }
        }
        return ans+(st.size()*2);
    }
};