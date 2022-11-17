class Solution {
public:
    string removeStars(string s) {
        stack<int>st;
        int count=0;
        for(auto c:s){
            if(c!='*') st.push(c);
            else if(!st.empty()) st.pop(),count++;
        }
        if(st.empty()) return "";
        int n=st.size();
        string res(n,' ');
        for(int i=n-1;i>=0;i--){
            res[i]=st.top();
            st.pop();
        }
        return res;
    }
};
//2 pass + Uses stack
//SC-->O(n)
//TC-->O(n)