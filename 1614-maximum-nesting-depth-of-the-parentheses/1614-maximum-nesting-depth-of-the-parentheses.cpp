class Solution {
public:
    int maxDepth(string s) {
        int res=0;
        stack<char>st;
        for(auto c :s){
            if(c=='(') st.push(c);
            else if(c==')'){
                int x=st.size();
                res=max(res,x);
                st.pop();
            }
        }
        return res;
    }
};

//Using Stack