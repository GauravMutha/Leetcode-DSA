class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        string res="";
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            if(s[i]=='c'){
                res="";
                while(!st.empty() && res.size()<3)
                    res+=st.top() , st.pop();
                if(res!="cba") return false;
            }
        }
        return st.empty();
    }
};

//SC-->O(n)
//TC--> O(n)