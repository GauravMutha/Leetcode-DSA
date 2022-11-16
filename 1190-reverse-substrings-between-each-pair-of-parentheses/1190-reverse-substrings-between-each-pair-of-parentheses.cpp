class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size(),j=0;
        string res;
        vector<int>pair(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                j=st.top();
                st.pop();
                pair[i]=j;
                pair[j]=i;
            }
        }
        for(int i=0,d=1;i<n;i+=d){
            if(s[i]=='(' || s[i]==')'){
                i=pair[i] , d=-d;
            }
            else res+=s[i];
        }
        return res;
    }
};
//WORMHOLE APPROACH
//Optimized
//1 pass
//TC-->O(n)
//SC-->O(n)