class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res="";
        stack<pair<char,int>>st;
        st.push({'#',0}); //to avoid emty stack
        for(int i=s.size()-1;i>=0;i--){
            if(st.top().first!=s[i]) st.push({s[i],1});
            else {
                st.top().second++;
                if(st.top().second==k) st.pop();
            }
        }
        while(st.top().first!='#')
            res.append(st.top().second,st.top().first) , st.pop();
        return res;
    }
};

//Same as approach 1 and 2 but: it uses only one stack and its TC is O(n) instesd of O(n*k)