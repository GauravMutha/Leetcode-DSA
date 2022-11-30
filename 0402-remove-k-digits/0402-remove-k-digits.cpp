class Solution {
public:
    string removeKdigits(string n, int k) {
        if(k==n.size()) return "0";
        string st;
        for(int i=0;i<n.size();i++){
            while(!st.empty() && st.back()>n[i] && k>=i-st.size()+1)
                st.pop_back();
            if(st.size()<(n.size()-k)) st.push_back(n[i]);
        }
        int i=0;
        for(i=0;i<st.size()-1;i++)
            if(st[i]!='0') break;
        st.erase(0,i);
        return (st=="") ? "0" : st;
    }
};